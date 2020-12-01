/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:15:45 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/22 19:42:35 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	ft_check_nbr(char *tab, char *str, int nbr, char c)
{
	char	**tmp;
	int		i;

	tmp = ft_split(tab, c);
	i = ft_count_table(tmp);
	if (i != nbr)
	{
		write(1, str, ft_strlen(str));
		double_free(tmp);
		return (0);
	}
	double_free(tmp);
	return (1);
}

int	ft_check_tab_between(char *tab, int min, int max, char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(tab, ',');
	while (tmp[i])
	{
		if (!ft_is_between(ft_atof(tmp[i]), min, max, str))
		{
			double_free(tmp);
			return (0);
		}
		i++;
	}
	double_free(tmp);
	return (1);
}

int	ft_check_tab_int(char *tab, char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(tab, ',');
	while (tmp[i])
	{
		if (!ft_is_int(tmp[i], str))
		{
			double_free(tmp);
			return (0);
		}
		i++;
	}
	double_free(tmp);
	return (1);
}

int	ft_check_tab_double(char *tab, char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(tab, ',');
	while (tmp[i])
	{
		if (!ft_is_double(tmp[i], str))
		{
			double_free(tmp);
			return (0);
		}
		i++;
	}
	double_free(tmp);
	return (1);
}
