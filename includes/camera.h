/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:41:07 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/22 19:38:54 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "ft_vectors.h"

typedef struct	s_camera
{
	t_vector		pos;
	t_vector		right;
	t_vector		Up;
	t_vector		BottomLeftPoint;
	t_vector		x_inc;
	t_vector		y_inc;
	t_vector		default_up;
	t_vector		look_at_point;
	t_vector		trans;
	t_vector		rot;
	int				found;
	double			fov;
	double			HalfWidth;
	double			aspectRatio;
	double			HalfHeight;
	struct s_camera	*next;
	struct s_camera	*prev;
}				t_camera;

#endif