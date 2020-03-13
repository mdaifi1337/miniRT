/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:53:00 by mdaifi            #+#    #+#             */
/*   Updated: 2020/02/26 17:12:39 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	int 	*mlx_data;
	int		bpp;
	int		endian;
	int		size_l;
}				t_mlx;
