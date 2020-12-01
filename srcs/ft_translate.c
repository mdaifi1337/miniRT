/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:41:24 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/29 17:54:00 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

static int	ft_check_trans(char *str, char *ch)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, ch, 2, ' '))
		return (0);
	if (!ft_check_vector(tab[1], ch, ','))
		return (0);
	return (1);
}

t_vector	ft_add_trs(char *str)
{
	t_vector	res;
	char		**tmp;

	tmp = ft_split(str, ',');
	res = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	return (res);
}

int	ft_trs_found(t_vector *trs, char *tab, char *str, int j)
{
	char		**tmp;

	if (ft_found(tab, "mv ", j))
	{
		tmp = ft_split(tab, ' ');
		if (!ft_check_trans(tab, str))
			exit(1);
		*trs = ft_vector_add(*trs, ft_add_trs(tmp[1]));
		double_free(tmp);
		return (1);
	}
	return (0);
}

static int	ft_previous_obj(char **tab, int i)
{
	if (!ft_strncmp(tab[i], "c ", 2) || !ft_strncmp(tab[i], "pl ", 3)
		|| !ft_strncmp(tab[i], "sq ", 3) || !ft_strncmp(tab[i], "cy ", 3))
		return (1);
	return (0);
}

t_vector	ft_trs_and_rot(char **tab, char *str, int *i, t_vector *rot)
{
	int			j;
	int			tmp;
	t_vector	trs;

	tmp = *i + 1;
	trs = (t_vector){0, 0, 0};
	while (tab[tmp])
	{
		j = 0;
		while (tab[tmp][j] == ' ')
			j++;
		if (ft_trs_found(&trs, tab[tmp], str, j))
			tmp++;
		else if (ft_rot_found(rot, tab[tmp], "rt ", j)
				&& ft_previous_obj(tab, *i))
			tmp++;
		else
		{
			*i = tmp - 1;
			return (trs);
		}
	}
	return (trs);
}
