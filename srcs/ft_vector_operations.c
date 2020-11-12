/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:42:40 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/06 17:12:10 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_OPERATIONS_H
# define FT_VECTOR_OPERATIONS_H

# include "../includes/mini_rt.h"

double		get_norm(t_vector res)
{
	return (sqrt(res.x * res.x + res.y * res.y + res.z * res.z));
}

void		normalize(t_vector *ret)
{
	double norm;

	norm = get_norm(*ret);
	ret->x /= norm;
	ret->y /= norm;
	ret->z /= norm;
}

t_vector	get_normalized(t_vector res)
{
	t_vector ret;

	ret = res;
	normalize(&ret);
	return (ret);
}

t_vector	cross_product(t_vector *v1, t_vector *v2)
{
	t_vector	res;

	res.x = (v1->y * v2->z) - (v1->z * v2->y);
	res.y = (v1->z * v2->x) - (v1->x * v2->z);
	res.z = (v1->x * v2->y) - (v1->y * v2->x);
	return (res);
}

t_vector	ft_negate_vector(t_vector v)
{
	t_vector	res;

	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	return (res);
}

#endif
