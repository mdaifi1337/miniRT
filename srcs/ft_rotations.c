/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:18:31 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/26 13:27:41 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

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

int			ft_check_rot(char *str, char *ch)
{
	if (!ft_check_vector(str, "Error, Invalid rotation value(s)..\n", ','))
	{
		write(1, ch, ft_strlen(ch));
		return (0);
	}
	return (1);
}

t_vector	ft_add_rot(char *str)
{
	t_vector	res;
	char		**tmp;

	tmp = ft_split(str, ',');
	res = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	return (res);
}
