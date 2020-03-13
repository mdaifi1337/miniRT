/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:07:12 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/13 18:24:01 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int	ft_ray_cast(t_env *e, t_scene *head)
{
	int	ret;

	ret = 0;
	e->object = NULL;
	while (head != NULL)
	{
		if (head->type == Tplane)
			check_plane(e, head, &ret);
		else if (head->type == Tsphere)
			check_sphere(e, head, &ret);
		else if (head->type == Tcylinder)
			check_cylinder(e, head, &ret);
		head = head->next;
	}
	return (ret);
}

int	ft_shadow_cast(t_env *e, t_scene *head)
{
	e->object = NULL;
	while (head != NULL)
	{
		if (head->type == Tsphere)
			if (ft_sphere_shadow(e, head))
				return (1);
		if (head->type == Tplane)
			if (ft_plane_shadow(e, head))
				return (1);
		if (head->type == Tcylinder)
			if (ft_cylinder_shadow(e, head))
				return (1);
		head = head->next;
	}
	return (0);
}