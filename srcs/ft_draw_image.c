/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:28:58 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/22 18:20:20 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void		ft_draw(t_env *e)
{
	camera(e);
	e->y = e->height - 1;
	while (e->y >= 0)
	{
		e->x = 0;
		while (e->x < e->width)
		{
			ft_make_ray(e, e->x, e->y);
			if (ft_ray_cast(e, e->scene_head))
			{
				ft_light(e, e->object, e->scene_head, e->light_list);
				if (e->save != 1)
				{
					e->mlx->mlx_data[(e->height - e->y - 1) * e->width + e->x] =
									get_int(e->phong);
				}
				if (e->save == 1)
					ft_store_bmp_data(e);
			}
			e->x++;
		}
		e->y--;
	}
}
