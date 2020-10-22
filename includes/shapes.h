/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:53:35 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/21 18:21:29 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# include "ft_vectors.h"

typedef enum	e_type
{
	Tsphere, Tplane, Tcylinder, Tsquare, Ttriangle
}				t_type;

typedef struct	s_scene
{
	void			*object;
	t_vector		normal;
	t_vector		intersect_point;
	t_color			color;
	t_type			type;
	struct s_scene	*next;
}				t_scene;

typedef struct	s_sphere
{
	t_vector	pos;
	t_vector	trans;
	t_color		color;
	int			radius;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	pos;
	t_vector	trans;
	t_vector	rot;
	t_color		color;
	t_vector	normal;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	pos;
	t_vector	trans;
	t_vector	rot;
	t_vector	normal;
	t_vector	start;
	t_vector	end;
	double		width;
	double		height;
	t_color		color;
}				t_cylinder;

typedef struct	s_square
{
	t_vector	pos;
	t_vector	trans;
	t_vector	rot;
	t_vector	normal;
	t_vector	up;
	t_vector	right;
	t_color		color;
	double		side;
} 				t_square;

typedef struct	s_triangle
{
	t_vector	A;
	t_vector	B;
	t_vector	C;
	t_color		color;

}				t_triangle;

#endif