/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:18:31 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/22 17:15:10 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

t_vector	ft_rot(t_vector v, double alpha, double beta, double gamma)
{
	t_vector	rot;

	rot.x = -v.z * sin(beta) + v.y * cos(beta) * sin(gamma) + v.x * cos(beta)
			* cos(gamma);
	rot.y = v.z * sin(alpha) * cos(beta) + v.y * (sin(alpha) * sin(beta)
			* sin(gamma) + cos(alpha) * cos(gamma)) + v.x * (sin(alpha)
			* sin(beta) * cos(gamma) - cos(alpha) * sin(gamma));
	rot.z = v.z * cos(alpha) * cos(beta) + v.y * (cos(alpha) * sin(beta)
			* sin(gamma) - sin(alpha) * cos(gamma)) + v.x * (cos(alpha)
			* sin(beta) * cos(gamma) + sin(alpha) * sin(gamma));
	return (rot);
}

int		ft_check_rot(char *str)
{
	char	**tmp;

	tmp = NULL;
	tmp = ft_split(str, ',');
	if (ft_check_vector(tmp, "Error, Invalid rotation value(s)..\n") == -1)
		return (-1);
	return (1);
}