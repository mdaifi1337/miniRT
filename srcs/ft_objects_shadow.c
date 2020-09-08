/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_shadow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:29:43 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/08 16:27:33 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int	ft_plane_shadow(t_env *e, t_scene *scene)
{
	t_plane	*plane;

	plane = (t_plane *)scene->object;
	if (intersectRayPlane(e, plane))
		return (1);
	return (0);
}

int	ft_sphere_shadow(t_env *e, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->object;
	if (intersectRaySphere(e, sphere))
		return (1);
	return (0);
}

int	ft_cylinder_shadow(t_env *e, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)scene->object;
	if (intersectRayCylinder(e, cylinder))
		return (1);
	return (0);
}

int	ft_triangle_shadow(t_env *e, t_scene *scene)
{
	t_triangle	*triangle;

	triangle = (t_triangle *)scene->object;
	if (intersectRayTriangle(e, triangle))
		return (1);
	return (0);
}

int	ft_square_shadow(t_env *e, t_scene *scene)
{
	t_square	*square;

	square = (t_square *)scene->object;
	if (intersectRaySquare(e, square))
		return (1);
	return (0);
}