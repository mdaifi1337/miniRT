/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_inter2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:39:59 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/22 18:03:28 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

static int	ft_int_ray_pl_sq(t_env *e, t_square *sq, double temp_dist)
{
	t_vector	inter_point;
	t_vector	temp;
	double		check[2];

	temp = ft_make_vector(0, 1, 0.1);
	sq->right = get_normalized(cross_product(&temp, &sq->normal));
	sq->up = get_normalized(cross_product(&sq->normal, &sq->right));
	sq->right = vector_scale(sq->side / 2, sq->right);
	sq->up = vector_scale(sq->side / 2, sq->up);
	inter_point = ft_vector_sub(ft_vector_add(e->ray.start,
				vector_scale(e->distance, e->ray.dir)), sq->pos);
	if (ft_vector_dot(sq->right, inter_point) <= 0)
		sq->right = vector_scale(-1, sq->right);
	if (ft_vector_dot(sq->up, inter_point) <= 0)
		sq->up = vector_scale(-1, sq->up);
	check[0] = acos(ft_vector_dot(sq->right, inter_point) /
			(get_norm(sq->right) * get_norm(inter_point)));
	check[1] = acos(ft_vector_dot(sq->up, inter_point) /
			(get_norm(sq->up) * get_norm(inter_point)));
	if (get_norm(inter_point) * cos(check[0]) < get_norm(sq->right) &&
		get_norm(inter_point) * cos(check[1]) < get_norm(sq->up))
		return (1);
	e->distance = temp_dist;
	return (0);
}

int			inter_ray_sq(t_env *e, t_square *sq)
{
	t_plane		*plane;
	double		temp_dist;

	temp_dist = e->distance;
	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->pos = sq->pos;
	plane->normal = sq->normal;
	if (inter_ray_pl(e, plane))
	{
		free(plane);
		return (ft_int_ray_pl_sq(e, sq, temp_dist));
	}
	free(plane);
	return (0);
}

static int	ft_calc_cy_vars(t_env *e, t_cylinder *cy, t_vector dist)
{
	double		m1;
	double		m2;

	e->sqrtdiscr = sqrtf(e->discr);
	e->t1 = (-e->b - e->sqrtdiscr) / (2 * e->a);
	e->t2 = (-e->b + e->sqrtdiscr) / (2 * e->a);
	m1 = ft_vector_dot(e->ray.dir, cy->normal) * e->t1
		+ ft_vector_dot(dist, cy->normal);
	m2 = ft_vector_dot(e->ray.dir, cy->normal) * e->t2
		+ ft_vector_dot(dist, cy->normal);
	if ((m1 > -(cy->height / 2) && m1 < (cy->height / 2)) && ((e->t1
		> 0.0001f && e->t1 < e->distance)))
	{
		e->distance = e->t1;
		return (1);
	}
	if ((m2 > -(cy->height / 2) && m2 < (cy->height / 2)) && ((e->t2
		> 0.0001f && e->t2 < e->distance)))
	{
		e->distance = e->t2;
		return (1);
	}
	return (0);
}

int			inter_ray_cy(t_env *e, t_cylinder *cy)
{
	t_vector	dist;

	dist = ft_vector_sub(e->ray.start, cy->pos);
	e->a = ft_vector_dot(e->ray.dir, e->ray.dir)
		- pow(ft_vector_dot(e->ray.dir, cy->normal), 2);
	e->b = 2 * (ft_vector_dot(e->ray.dir, dist) - (ft_vector_dot(e->ray.dir,
		cy->normal) * ft_vector_dot(dist, cy->normal)));
	e->c = ft_vector_dot(dist, dist) - pow(ft_vector_dot(dist, cy->normal), 2)
		- ((cy->width / 2) * (cy->width / 2));
	e->discr = (e->b * e->b) - (4 * e->a * e->c);
	if (e->discr < 0)
		return (0);
	else
		return (ft_calc_cy_vars(e, cy, dist));
	return (0);
}
