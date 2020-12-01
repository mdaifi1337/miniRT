/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:20:21 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/26 17:31:07 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	sphere_normal(t_env *e, t_scene *scene)
{
	t_vector	v;
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object;
	scene->normal = ft_vector_sub(scene->inter_point, sphere->pos);
	scene->normal = get_normalized(scene->normal);
	v = ft_vector_sub(ft_vector_add(e->curr_cam.pos, e->ray.dir),
		scene->inter_point);
	if (ft_vector_dot(v, scene->normal) <= 0)
		scene->normal = vector_scale(-1, scene->normal);
}

void	plane_normal(t_env *e, t_scene *scene)
{
	t_vector	v;
	t_plane		*plane;

	plane = (t_plane *)scene->object;
	scene->normal = plane->normal;
	v = ft_vector_sub(ft_vector_add(e->curr_cam.pos, e->ray.dir),
		scene->inter_point);
	if (ft_vector_dot(v, scene->normal) <= 0)
		scene->normal = vector_scale(-1, scene->normal);
}

void	cylinder_normal(t_env *e, t_scene *scene)
{
	t_vector	v;
	t_cylinder	*cy;
	t_vector	dist;
	double		m;

	cy = (t_cylinder *)scene->object;
	dist = ft_vector_sub(e->ray.start, cy->pos);
	m = ft_vector_dot(e->ray.dir, vector_scale(e->distance, cy->normal))
		+ ft_vector_dot(dist, cy->normal);
	scene->normal = ft_vector_sub(ft_vector_sub(scene->inter_point, cy->pos),
		vector_scale(m, cy->normal));
	scene->normal = get_normalized(scene->normal);
	v = ft_vector_sub(ft_vector_add(e->curr_cam.pos, e->ray.dir),
		scene->inter_point);
	if (ft_vector_dot(v, scene->normal) <= 0)
		scene->normal = vector_scale(-1, scene->normal);
}

void	square_normal(t_env *e, t_scene *scene)
{
	t_vector	v;
	t_square	*square;

	square = (t_square *)scene->object;
	scene->normal = square->normal;
	v = ft_vector_sub(ft_vector_add(e->curr_cam.pos, e->ray.dir),
		scene->inter_point);
	if (ft_vector_dot(v, scene->normal) <= 0)
		scene->normal = vector_scale(-1, scene->normal);
}

void	triangle_normal(t_env *e, t_scene *scene)
{
	t_triangle	*triangle;
	t_vector	v1;
	t_vector	v2;
	t_vector	v;

	triangle = (t_triangle *)scene->object;
	v1 = ft_vector_sub(triangle->b, triangle->a);
	v2 = ft_vector_sub(triangle->c, triangle->a);
	scene->normal = get_normalized(cross_product(&v2, &v1));
	v = ft_vector_sub(ft_vector_add(e->curr_cam.pos, e->ray.dir),
		scene->inter_point);
	if (ft_vector_dot(v, scene->normal) <= 0)
		scene->normal = vector_scale(-1, scene->normal);
}
