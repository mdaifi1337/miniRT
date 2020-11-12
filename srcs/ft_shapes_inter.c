/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_inter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:26:17 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/12 17:54:31 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	inter_ray_sp(t_env *e, t_sphere *s)
{
	t_vector	dist;

	dist = ft_vector_sub(e->ray.start, s->pos);
	e->a = ft_vector_dot(e->ray.dir, e->ray.dir);
	e->b = 2 * ft_vector_dot(e->ray.dir, dist);
	e->c = ft_vector_dot(dist, dist) - (s->radius * s->radius);
	e->discr = (e->b * e->b) - (4 * e->a * e->c);
	if (e->discr < 0)
		return (0);
	else
	{
		e->sqrtdiscr = sqrt(e->discr);
		e->t1 = (-e->b - e->sqrtdiscr) / (2 * e->a);
		e->t2 = (-e->b + e->sqrtdiscr) / (2 * e->a);
		return (ft_smallest_value(e));
	}
}

int	inter_ray_pl(t_env *e, t_plane *plane)
{
	double		tmp;
	double		denom;
	t_vector	inter_point;

	denom = ft_vector_dot(e->ray.dir, plane->normal);
	if (fabs(denom) > 0.0001)
	{
		inter_point = ft_vector_sub(e->ray.start, plane->pos);
		tmp = -ft_vector_dot(inter_point, plane->normal) / denom;
		if (tmp > 0 && tmp > 0.0001 && tmp < e->distance)
		{
			e->distance = tmp;
			return (1);
		}
	}
	return (0);
}

int	inter_ray_tr(t_env *e, t_triangle *triangle)
{
	t_tr_vars	tr;

	tr.v1 = ft_vector_sub(triangle->b, triangle->a);
	tr.v2 = ft_vector_sub(triangle->c, triangle->a);
	tr.ray_cross_v2 = cross_product(&e->ray.dir, &tr.v2);
	tr.det = ft_vector_dot(tr.v1, tr.ray_cross_v2);
	if (tr.det > -0.0000001 && tr.det < 0.0000001)
		return (0);
	tr.p = ft_vector_sub(e->ray.start, triangle->a);
	tr.u = (1.0 / tr.det) * ft_vector_dot(tr.p, tr.ray_cross_v2);
	if (tr.u < 0.0 || tr.u > 1.0)
		return (0);
	tr.o_cross_v1 = cross_product(&tr.p, &tr.v1);
	tr.v = (1.0 / tr.det) * ft_vector_dot(e->ray.dir, tr.o_cross_v1);
	if (tr.v < 0.0 || (tr.u + tr.v) > 1.0)
		return (0);
	tr.new_dist = (1.0 / tr.det) * ft_vector_dot(tr.v2, tr.o_cross_v1);
	if (tr.new_dist > 0.0000001 && tr.new_dist < e->distance)
	{
		e->distance = tr.new_dist;
		return (1);
	}
	return (0);
}
