/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:37:28 by mdaifi            #+#    #+#             */
/*   Updated: 2020/02/27 22:38:54 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTORS_H
# define FT_VECTORS_H

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_color
{
	double	red;
	double	green;
	double	blue;
}				t_color;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
	t_vector	viewDirection;
}				t_ray;

#endif