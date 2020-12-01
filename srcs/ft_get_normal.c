/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:20:23 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/21 19:23:38 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void		ft_get_normal(t_env *e, t_scene *head)
{
	t_vector	scaled;
	t_scene		*scene;

	scene = head;
	scaled = vector_scale(e->distance, e->ray.dir);
	scaled = ft_vector_add(scaled, vector_scale(1e-6 * 10, scene->normal));
	scene->inter_point = ft_vector_add(e->ray.start, scaled);
	if (scene->type == Tplane)
		plane_normal(e, scene);
	else if (scene->type == Tsphere)
		sphere_normal(e, scene);
	else if (scene->type == Tsquare)
		square_normal(e, scene);
	else if (scene->type == Tcylinder)
		cylinder_normal(e, scene);
	else if (scene->type == Ttriangle)
		triangle_normal(e, scene);
}
