/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:26:19 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/21 19:29:24 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

static void	ft_draw_next_cam_image(t_env *e)
{
	char	*str;

	str = ft_itoa(e->cam_count);
	mlx_clear_window(e->mlx->mlx_ptr, e->mlx->mlx_win);
	mlx_destroy_image(e->mlx->mlx_ptr, e->mlx->mlx_img);
	e->mlx->mlx_img = mlx_new_image(e->mlx->mlx_ptr, e->width, e->height);
	ft_draw(e);
	mlx_put_image_to_window(e->mlx->mlx_ptr, e->mlx->mlx_win,
									e->mlx->mlx_img, 0, 0);
	mlx_string_put(e->mlx->mlx_ptr, e->mlx->mlx_win, 10, 10,
				0x8B4513, "Camera ");
	mlx_string_put(e->mlx->mlx_ptr, e->mlx->mlx_win, 110, 10, 0x8B4513, "-");
	mlx_string_put(e->mlx->mlx_ptr, e->mlx->mlx_win, 80, 10, 0x8B4513, str);
	mlx_string_put(e->mlx->mlx_ptr, e->mlx->mlx_win, 140,
				10, 0x8B4513, "Press 'c' to switch camera");
	free(str);
}

int			key(int khook, t_env *e)
{
	if (khook == 53)
		exit(0);
	if (khook == 8)
	{
		if (e->cam_list->next == NULL)
			return (0);
		else if (e->it_cam->next == NULL)
		{
			e->cam_count = 1;
			e->it_cam = e->cam_list;
			e->curr_cam = *(e->it_cam);
			ft_draw_next_cam_image(e);
		}
		else
		{
			e->cam_count++;
			e->curr_cam = *(e->it_cam->next);
			e->it_cam = e->it_cam->next;
			ft_draw_next_cam_image(e);
		}
	}
	return (0);
}

int			close_win(t_env *e)
{
	(void)e;
	exit(0);
}
