/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:24:32 by mdaifi            #+#    #+#             */
/*   Updated: 2020/12/01 17:32:10 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

/*
**clamp_colors aka 0 > color > 255
** bleu
** green
** red
*/

int			main(int argc, char **argv)
{
	t_env	e;

	ft_check_file_ext(argc, argv);
	ft_check_second_arg(&e, argc, argv[2]);
	init_vars(&e);
	ft_parse(argv[1], &e);
	if (e.save == 1)
		ft_save_bmp(&e);
	e.mlx = init(&e);
	ft_draw(&e);
	mlx_hook(e.mlx->mlx_win, 17, 0, &close_win, &e);
	mlx_hook(e.mlx->mlx_win, 2, 0, key, &e);
	mlx_put_image_to_window(e.mlx->mlx_ptr, e.mlx->mlx_win,
							e.mlx->mlx_img, 0, 0);
	mlx_string_put(e.mlx->mlx_ptr, e.mlx->mlx_win, 10, 10,
				0x8B4513, "Camera 1");
	mlx_string_put(e.mlx->mlx_ptr, e.mlx->mlx_win, 110, 10, 0x8B4513, "-");
	mlx_string_put(e.mlx->mlx_ptr, e.mlx->mlx_win, 140,
				10, 0x8B4513, "Press 'c' to switch camera");
	mlx_loop(e.mlx->mlx_ptr);
	return (0);
}
