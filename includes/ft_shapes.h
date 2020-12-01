/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:53:35 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/18 17:43:47 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHAPES_H
# define FT_SHAPES_H
# include "ft_vectors.h"

typedef enum	e_type
{
	Tsphere, Tplane, Tcylinder, Tsquare, Ttriangle
}				t_type;

typedef struct	s_scene
{
	void			*object;
	t_vector		normal;
	t_vector		inter_point;
	t_color			color;
	t_type			type;
	struct s_scene	*next;
}				t_scene;

typedef struct	s_sphere
{
	t_vector	pos;
	t_vector	trs;
	t_color		color;
	int			radius;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	pos;
	t_vector	trs;
	t_vector	rot;
	t_color		color;
	t_vector	normal;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	pos;
	t_vector	trs;
	t_vector	rot;
	t_vector	normal;
	t_vector	start;
	t_vector	end;
	t_color		color;
	double		width;
	double		height;
}				t_cylinder;

typedef struct	s_square
{
	t_vector	pos;
	t_vector	trs;
	t_vector	rot;
	t_vector	normal;
	t_vector	up;
	t_vector	right;
	t_color		color;
	double		side;
}				t_square;

typedef struct	s_triangle
{
	t_vector	a;
	t_vector	b;
	t_vector	c;
	t_color		color;
	t_vector	trs;
}				t_triangle;

typedef struct	s_tr_vars
{
	t_vector	p;
	t_vector	vec[3];
	t_vector	v1;
	t_vector	v2;
	t_vector	o_cross_v1;
	t_vector	ray_cross_v2;
	double		det;
	double		u;
	double		v;
	double		new_dist;
}				t_tr_vars;

#endif
