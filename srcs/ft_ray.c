/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:44:04 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/21 17:10:51 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void		ft_make_ray(t_env *e, int x, int y)
{
	t_vector	viewplanepoint;

	e->distance = RAY_DIS_MAX;
	viewplanepoint = ft_vector_add(ft_vector_add(e->curr_cam.bottomleftpoint,
	vector_scale((double)x / e->width, e->curr_cam.x_inc)),
	vector_scale((double)y / e->height, e->curr_cam.y_inc));
	e->ray.start = e->curr_cam.pos;
	e->ray.dir = get_normalized(ft_vector_sub(viewplanepoint, e->curr_cam.pos));
}
