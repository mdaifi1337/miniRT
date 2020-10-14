/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_intersections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:26:17 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/14 17:06:59 by mdaifi           ###   ########.fr       */
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

int	intersectRayTriangle(t_env *e, t_triangle *triangle)
{
	t_vector	P;
	t_vector	vec[3];
	t_vector	v1;
	t_vector	v2;
	t_vector	O_cross_v1;
	t_vector	ray_cross_v2;
	double		det;
	double		u;
	double		v;
	double		new_dist;

	v1 = ft_vector_sub(triangle->B, triangle->A);
	v2 = ft_vector_sub(triangle->C, triangle->A);
	ray_cross_v2 = cross_product(&e->ray.dir, &v2);
	det = ft_vector_dot(v1, ray_cross_v2);
	if (det < 0.0000001 && det > -0.0000001)
		return (0);
	P = ft_vector_sub(e->ray.start, triangle->A);
	u = (1.0 / det) * ft_vector_dot(P, ray_cross_v2);
	if (u < 0.0 || u > 1.0)
		return (0);
	O_cross_v1 = cross_product(&P, &v1);
	v = (1.0 / det) * ft_vector_dot(e->ray.dir, O_cross_v1);
	if (v < 0.0 || (u + v) > 1.0)
		return (0);
	new_dist = (1.0 / det) * ft_vector_dot(v2, O_cross_v1);
	if (new_dist > 0.0000001 && new_dist < e->distance)
	{
		e->distance = new_dist;
		return (1);
	}
	return (0);
}

int	intersectRaySquare(t_env *e, t_square *square)
{
	t_vector	temp;
	t_vector	inter_point;
	t_plane		*plane;
	double		check[2];
	double		temp_dist;

	temp_dist = e->distance;
	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->pos = square->pos;
	plane->normal = square->normal;
	if (intersectRayPlane(e, plane))
	{
		free(plane);
		temp = ft_make_vector(0, 1, 0.1);
		square->right = getNormalized(cross_product(&temp, &square->normal));
		square->up = getNormalized(cross_product(&square->normal, &square->right));
		square->right = vectorScale(square->side / 2, square->right);
		square->up = vectorScale(square->side / 2, square->up);
		inter_point = ft_vector_sub(ft_vector_add(e->ray.start, vectorScale(e->distance, e->ray.dir)), square->pos);
		if (ft_vector_dot(square->right, inter_point) <= 0)
			square->right = vectorScale(-1, square->right);
		if (ft_vector_dot(square->up, inter_point) <= 0)
			square->up = vectorScale(-1, square->up);
		check[0] = acos(ft_vector_dot(square->right, inter_point) / (getNorm(square->right) * getNorm(inter_point)));
		check[1] = acos(ft_vector_dot(square->up, inter_point) / (getNorm(square->up) * getNorm(inter_point)));
		if (getNorm(inter_point) * cos(check[0]) < getNorm(square->right) &&
			getNorm(inter_point) * cos(check[1]) < getNorm(square->up))
			return (1);
		e->distance = temp_dist;
		return (0);
	}
	return (0);
}