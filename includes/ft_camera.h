/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:41:07 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/07 18:15:12 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAMERA_H
# define FT_CAMERA_H
# include "ft_vectors.h"

typedef struct	s_camera
{
	t_vector		pos;
	t_vector		right;
	t_vector		up;
	t_vector		bottomleftpoint;
	t_vector		x_inc;
	t_vector		y_inc;
	t_vector		default_up;
	t_vector		look_at;
	t_vector		trs;
	t_vector		rot;
	int				found;
	double			fov;
	double			halfwidth;
	double			aspectratio;
	double			halfheight;
	struct s_camera	*next;
}				t_camera;

#endif
