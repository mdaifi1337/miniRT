/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_intersections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:26:17 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/10 18:16:06 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int intersectRaySphere(t_env *e, t_sphere *s)
{
	t_vector	dist;

	dist = ft_vector_sub(s->pos, e->ray.start);
	e->a = ft_vector_dot(e->ray.dir, e->ray.dir);
	e->b = 2 * ft_vector_dot(e->ray.dir, dist);
	e->c = ft_vector_dot(dist, dist) - (s->radius * s->radius);
	e->discr = (e->b * e->b) - (4 * e->a * e->c);
	if (e->discr < 0) 
		return (0);
	else
	{
		e->sqrtdiscr = sqrtf(e->discr);
		e->t1 = (e->b - e->sqrtdiscr)/(2 * e->a);
		e->t2 = (e->b + e->sqrtdiscr)/(2 * e->a);
		if(e->t2 > e->t1)
			e->t2 = e->t1;
		if((e->t2 > 0.001f) && (e->t2 < e->distance))
		{
			e->distance = e->t2;
			return (1);
		}
		else
			return (0);
	}
}

int	intersectRayPlane(t_env *e, t_plane *plane)
{
	double		tmp;
	double		denom;
	t_vector	inter_point;
	
	
	denom = ft_vector_dot(e->ray.dir, plane->normal);
	if (fabs(denom) > 0.001f)
	{
		inter_point = ft_vector_sub(plane->pos, e->ray.start);
		tmp = ft_vector_dot(inter_point, plane->normal) / denom;
		if (tmp > 0.0001f && tmp < e->distance)
		{
			e->distance = tmp;
			return (1);
		}
	}
	return (0);
}

int	intersectRayCylinder(t_env *e, t_cylinder *cylinder)
{
	t_vector	dist;
	t_vector	check;
	double		m1;
	double 		m2;


	dist = ft_vector_sub(cylinder->pos, e->ray.start);
	e->a = ft_vector_dot(e->ray.dir, e->ray.dir) - pow(ft_vector_dot(e->ray.dir, cylinder->normal), 2);
	e->b = 2 * (ft_vector_dot(e->ray.dir, dist) - (ft_vector_dot(e->ray.dir, cylinder->normal) * ft_vector_dot(dist, cylinder->normal)));
	e->c = ft_vector_dot(dist, dist) - pow(ft_vector_dot(dist, cylinder->normal), 2) - ((cylinder->width / 2) * (cylinder->width / 2));
	e->discr = (e->b * e->b) - (4 * e->a * e->c);
	e->sqrtdiscr = sqrtf(e->discr);
	e->t1 = (e->b - e->sqrtdiscr)/(2 * e->a);
	e->t2 = (e->b + e->sqrtdiscr)/(2 * e->a);
	if(e->discr < 0)
		return (0);
	else
	{
		dist = vectorScale(-1, dist);
		m1 = ft_vector_dot(e->ray.dir, vectorScale(e->t1, cylinder->normal)) + ft_vector_dot(dist, cylinder->normal);
		m2 = ft_vector_dot(e->ray.dir, vectorScale(e->t2, cylinder->normal)) + ft_vector_dot(dist, cylinder->normal);
		if ((m1 > -(cylinder->height / 2) && m1 < (cylinder->height / 2)) && ((e->t1 > 0.0001f && e->t1 < e->distance)))
		{
			e->distance = e->t1;
			return (1);
		}
		if ((m2 > -(cylinder->height / 2) && m2 < (cylinder->height / 2)) && ((e->t2 > 0.0001f && e->t2 < e->distance)))
		{
			e->distance = e->t2;
			return (1);
		}
	}
	return (0);
}