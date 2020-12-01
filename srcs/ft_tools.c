/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:18:07 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/22 19:53:43 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

static int	check_sign(const char *str, int i)
{
	int		sign;

	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	return (sign);
}

double		ft_atof(const char *str)
{
	int		i;
	int		point;
	int		decimal;
	double	sign;
	double	result;

	result = 0;
	point = 0;
	i = -1;
	sign = check_sign(str, i);
	while (str[++i])
	{
		if (str[i] == '.')
		{
			point = 1;
			i++;
		}
		decimal = str[i] - '0';
		if (decimal >= 0 && decimal <= 9)
		{
			point == 1 ? sign /= 10.0f : 0;
			result = result * 10.0f + decimal;
		}
	}
	return (result * sign);
}

double		ft_rad(int angle)
{
	return ((angle * PI) / 180);
}
