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
	t_vector		dist;
	double		m1;
	double		m2;

	cylinder = (t_cylinder *)scene->object;
	cylinder->normal = getNormalized(cylinder->normal);
	if (intersectRayCylinder(e, cylinder))
	{
		*ret = 1;
		ft_get_normal(e, scene);
		e->object = scene;
	}
}