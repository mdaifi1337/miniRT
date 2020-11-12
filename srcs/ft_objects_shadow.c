/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_shadow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:29:43 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/05 18:51:02 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	ft_plane_shadow(t_env *e, t_scene *scene)
{
	t_plane	*plane;

	plane = (t_plane *)scene->object;
	if (inter_ray_pl(e, plane))
		return (1);
	return (0);
}

int	ft_sphere_shadow(t_env *e, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object;
	if (inter_ray_sp(e, sphere))
		return (1);
	return (0);
}

int	ft_cylinder_shadow(t_env *e, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)scene->object;
	if (inter_ray_cy(e, cylinder))
		return (1);
	return (0);
}

int	ft_triangle_shadow(t_env *e, t_scene *scene)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)scene->object;
	if (inter_ray_tr(e, triangle))
		return (1);
	return (0);
}

int	ft_square_shadow(t_env *e, t_scene *scene)
{
	t_square	*square;

	square = (t_square *)scene->object;
	if (inter_ray_sq(e, square))
		return (1);
	return (0);
}
