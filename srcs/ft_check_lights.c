/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:14:13 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/26 18:12:48 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

static int	ft_check_ambient_values(char **str, int i)
{
	char	**tab;

	tab = ft_split(str[i], ' ');
	if (!ft_check_nbr(str[i],
		"Error\nMissing or extra Ambient value(s) !..\n", 3, ' '))
		return (ft_free_error(tab));
	if (!ft_between(tab[1], "Error\nInvalid Ambient intensity !..\n", 0, 1))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[2], "Error\nInvalid Ambient color value(s) !..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int			ft_check_ambient(t_env *e, char **str)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == 'A' && str[i][1] == ' ')
		{
			e->ambient.found += 1;
			if (e->ambient.found > 1)
			{
				write(1, "Error\nDuplicate Ambient !..\n", 29);
				return (0);
			}
			if (!ft_check_ambient_values(str, i))
				return (0);
		}
	}
	if (e->ambient.found == 0)
	{
		write(1, "Error\nAmbient not found !..\n", 29);
		return (0);
	}
	return (1);
}

int			ft_check_light(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str,
		"Error\nMissing or extra Light value(s) !..\n", 4, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Error\nInvalid Light position !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_between(tab[2], "Error\nInvalid Light intensity !..\n", 0, 1))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[3], "Error\nInvalid Light color value(s) !..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}
