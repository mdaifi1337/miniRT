/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:50:16 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/05 18:35:19 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITMAP_H
# define FT_BITMAP_H
# include "fcntl.h"

typedef struct	s_bfh
{
	unsigned char	type;
	int				filesize;
	short			reserved1;
	short			reserved2;
	unsigned int	off_bits;
}				t_bfh;

typedef struct	s_bih
{
	unsigned int	size;
	unsigned int	width;
	unsigned int	height;
	short			planes;
	short			bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_y;
	unsigned int	ppm_x;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_bih;

typedef struct	s_bmp_vars
{
	unsigned char	*header;
	unsigned char	*buf;
	mode_t			mode;
	int				fd;
	int				width_in_bytes;
}				t_bmp_vars;

#endif
