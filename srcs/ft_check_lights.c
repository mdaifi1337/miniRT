/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:14:13 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 16:57:25 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int		ft_check_ambient(t_env *e, char **str)
{
	char		**tab;
	char		**temp;
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == 'A')
		{
			e->ambient.found++;
			if (e->ambient.found > 1)
			{
				write(1, "Error, Duplicate Ambient !..\n", 30);
				return (-1);
			}
			tab = ft_split(str[i], ' ');
			if (ft_check_commas(tab) == -1)
				return (ft_free_error(tab));
			if (ft_check_nbr(tab, "Error, Missing or extra Ambient value(s) !..\n", 3) == -1)
				return (-1);
			if (ft_check_between(tab[1], "Error, Invalid Ambient intensity...\n", 0, 1) == -1)
				return (ft_free_error(tab));
			temp = ft_split(tab[2], ',');
			if (ft_check_color(temp, "Error, Invalid Ambient color value(s)...\n") == -1)
				return (ft_free_error(tab));
			double_free(temp);
			double_free(tab);
		}
	}
	if (e->ambient.found == 0)
	{
		write(1, "Error, Ambient not found !..\n", 30);
		return (-1);
	}
	return (1);
}

int     ft_check_light(char *str)
{
    char		**tab;
	char		**temp;

	tab = NULL;
	temp = NULL;
	tab = ft_split(str, ' ');
	if (ft_check_commas(tab) == -1)
		return (ft_free_error(tab));
	if (ft_check_nbr(tab, "Error, Missing or extra Light value(s) !..\n", 4) == -1)
        return (-1);
	temp = ft_split(tab[1], ',');
	if (ft_check_vector(temp, "Error, Invalid Light position...\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	if (ft_check_between(tab[2], "Error, Invalid Light intensity...\n", 0, 1) == -1)
		return (ft_free_error(tab));
	temp = ft_split(tab[3], ',');
	if (ft_check_color(temp, "Error, Invalid Light color value(s)...\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	double_free(tab);
	return (1);
}