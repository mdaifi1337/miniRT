/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:42:23 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/06 18:27:55 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

void	check_sphere(t_env *e, t_scene *scene, int *ret)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object;
	if (intersectRaySphere(e, sphere))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}

void	check_plane(t_env *e, t_scene *scene, int *ret)
{
	t_plane		*plane;

	plane = (t_plane *)scene->object;
	if (intersectRayPlane(e, plane))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}

void	check_cylinder(t_env *e, t_scene *scene, int *ret)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)scene->object;
	if (intersectRayCylinder(e, cylinder))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}

void	check_triangle(t_env *e, t_scene *scene, int *ret)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)scene->object;
	if (intersectRayTriangle(e, triangle))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}

void	check_square(t_env *e, t_scene *scene, int *ret)
{
	t_square	*square;

	square = (t_square *)scene->object;
	if (intersectRaySquare(e, square))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}