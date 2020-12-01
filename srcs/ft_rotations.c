/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:18:31 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/29 17:35:31 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_vector	ft_rot(t_vector v, double alpha, double beta, double gamma)
{
	t_vector	rot;

	rot = (t_vector){0, 0, 0};
	rot.x = -v.z * sin(beta) + v.y * cos(beta) * sin(gamma)
			+ v.x * cos(beta) * cos(gamma);
	rot.y = v.z * sin(alpha) * cos(beta) + v.y * (sin(alpha) * sin(beta)
			* sin(gamma) + cos(alpha) * cos(gamma)) + v.x * (sin(alpha)
			* sin(beta) * cos(gamma) - cos(alpha) * sin(gamma));
	rot.z = v.z * cos(alpha) * cos(beta) + v.y * (cos(alpha) * sin(beta)
			* sin(gamma) - sin(alpha) * cos(gamma)) + v.x * (cos(alpha)
			* sin(beta) * cos(gamma) + sin(alpha) * sin(gamma));
	return (rot);
}

static int	ft_check_rot(char *str, char *ch)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, ch, 2, ' '))
		return (0);
	if (!ft_check_vector(tab[1], ch, ','))
		return (0);
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

int	ft_rot_found(t_vector *rot, char *tab, char *str, int j)
{
	char		**tmp;

	if (ft_found(tab, "rt ", j))
	{
		tmp = ft_split(tab, ' ');
		if (!ft_check_rot(tab, str))
			exit(1);
		if (rot != NULL)
			*rot = ft_vector_add(*rot, ft_add_rot(tmp[1]));
		double_free(tmp);
		return (1);
	}
	return (0);
}

t_vector	ft_rotate(char **tab, char *str, int *i)
{
	int			j;
	int			tmp;
	t_vector	rot;

	rot = (t_vector){0, 0, 0};
	tmp = *i + 1;
	while (tab[tmp])
	{
		j = 0;
		while (tab[tmp][j] == ' ')
			j++;
		if (ft_rot_found(&rot, tab[tmp], str, j))
			tmp++;
		else if (ft_found(tab[tmp], "mv ", j))
			tmp++;
		else
		{
			*i = tmp - 1;
			return (rot);
		}
	}
	return (rot);
}
