/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:10:11 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/03 20:22:23 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_bih	ft_init_bmp_info_header(t_env *e)
{
	t_bih	bih;
	int		width_in_bytes;

	bih.size = 40;
	bih.width = e->width;
	bih.height = e->height;
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	width_in_bytes = (((e->width * bih.bit_count) + 31) / 32) * 4;
	bih.image_size = width_in_bytes * e->height;
	bih.ppm_x = 0;
	bih.ppm_y = 0;
	bih.clr_used = 0;
	bih.clr_important = 0;
	return (bih);
}

t_bfh	ft_init_bmp_header(t_bih bih)
{
	t_bfh	bfh;

	ft_memcpy(&bfh.type, "BM", 2);
	bfh.filesize = 54 + bih.image_size;
	bfh.off_bits = 54;
	return (bfh);
}
