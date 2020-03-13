/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:36:51 by mdaifi            #+#    #+#             */
/*   Updated: 2020/02/28 15:21:33 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_vectors.h"

t_vector	ft_vector_add(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector	ft_vector_sub(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vector	vectorScale(double c, t_vector v)
{
    t_vector	result;
	
	result = (t_vector){v.x * c, v.y * c, v.z * c};
    return result;
}

double		ft_vector_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	ft_make_vector(double x, double y, double z)
{
	t_vector	vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}