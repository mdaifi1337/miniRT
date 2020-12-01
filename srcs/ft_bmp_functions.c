/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:54:27 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/22 18:21:53 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

unsigned char	*ft_bmp_header(t_bfh bfh, t_bih bih)
{
	unsigned char	*header;

	if (!(header = malloc(54 * sizeof(unsigned char))))
		return (NULL);
	ft_memset(header, 0, 54);
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &bfh.filesize, 4);
	ft_memcpy(header + 10, &bfh.off_bits, 4);
	ft_memcpy(header + 14, &bih.size, 4);
	ft_memcpy(header + 18, &bih.width, 4);
	ft_memcpy(header + 22, &bih.height, 4);
	ft_memcpy(header + 26, &bih.planes, 2);
	ft_memcpy(header + 28, &bih.bit_count, 2);
	ft_memcpy(header + 34, &bih.image_size, 4);
	return (header);
}

void			ft_store_bmp_data(t_env *e)
{
	e->bmp.buf[e->y * e->bmp.width_in_bytes + e->x * 3 + 0] =
	e->phong.blue * 255;
	e->bmp.buf[e->y * e->bmp.width_in_bytes + e->x * 3 + 1] =
	e->phong.green * 255;
	e->bmp.buf[e->y * e->bmp.width_in_bytes + e->x * 3 + 2] =
	e->phong.red * 255;
}

static void		ft_write_bmp_file(t_bmp_vars *bmp, t_bih bih)
{
	bmp->mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	bmp->fd = open("miniRT.bmp", O_WRONLY | O_CREAT | O_TRUNC, bmp->mode);
	write(bmp->fd, bmp->header, 54);
	write(bmp->fd, (char*)bmp->buf, bih.image_size);
	close(bmp->fd);
}

static void		ft_init_bmp(t_env *e, t_bfh *bfh, t_bih *bih)
{
	*bih = ft_init_bmp_info_header(e);
	*bfh = ft_init_bmp_header(*bih);
	e->bmp.buf = malloc(bfh->filesize);
	e->bmp.width_in_bytes = ((bih->width * bih->bit_count + 31) / 32) * 4;
	e->bmp.header = ft_bmp_header(*bfh, *bih);
}

void			ft_save_bmp(t_env *e)
{
	t_bfh		bfh;
	t_bih		bih;

	ft_init_bmp(e, &bfh, &bih);
	ft_draw(e);
	ft_write_bmp_file(&e->bmp, bih);
	exit(0);
}
