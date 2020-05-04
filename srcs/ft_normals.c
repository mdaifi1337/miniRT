/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:20:21 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/09 15:32:44 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

void	sphere_normal(t_scene *scene)
{
	t_sphere	*sphere;
	sphere = (t_sphere *)scene->object;
	scene->normal = ft_vector_sub(scene->intersect_point, sphere->pos);
	scene->normal = getNormalized(scene->normal);
}

void	plane_normal(t_scene *scene)
{
	t_plane		*plane;

	plane = (t_plane *)scene->object;
	scene->normal = plane->normal;
	if (ft_vector_dot(scene->intersect_point, plane->normal) > 0)
		scene->normal = vectorScale(-1, plane->normal);
}

void	cylinder_normal(t_env *e, t_scene *scene)
{
	t_cylinder		*cylinder;
	t_vector		dist;
	double			m;

	cylinder = (t_cylinder *)scene->object;
	dist = ft_vector_sub(e->ray.start, cylinder->pos);
	m = ft_vector_dot(e->ray.dir, vectorScale(e->distance, cylinder->normal)) + ft_vector_dot(dist, cylinder->normal);
	scene->normal = ft_vector_sub(ft_vector_sub(scene->intersect_point, cylinder->pos), vectorScale(m, cylinder->normal));
	scene->normal = getNormalized(scene->normal);
	if (ft_vector_dot(scene->intersect_point, scene->normal) > 0)
		scene->normal = vectorScale(-1, scene->normal);
}

void	square_normal(t_scene *scene)
{
	t_square		*square;

	square = (t_square *)scene->object;
	scene->normal = square->normal;
}

void	triangle_normal(t_scene *scene)
{
	t_triangle		*triangle;
	t_vector		v1;
	t_vector		v2;

	triangle = (t_triangle *)scene->object;
	v1 = ft_vector_sub(triangle->B, triangle->A);
	v2 =  ft_vector_sub(triangle->C, triangle->A);
	scene->normal = cross_product(&v1, &v2);
	scene->normal = getNormalized(scene->normal);
}

void		ft_get_normal(t_env *e, t_scene *head)
{
	t_vector	scaled;
	t_scene		*scene;

	scene = head;
	scaled = vectorScale(e->distance, e->ray.dir);
	scaled = ft_vector_add(scaled, vectorScale(1e-6 * 10, scene->normal));
	scene->intersect_point = ft_vector_add(e->ray.start, scaled);
	if (scene->type == Tplane)
		plane_normal(scene);
	else if (scene->type == Tsphere)
		sphere_normal(scene);
	else if (scene->type == Tsquare)
		square_normal(scene);
	else if (scene->type == Tcylinder)
		cylinder_normal(e, scene);
	else if (scene->type == Ttriangle)
		triangle_normal(scene);
}