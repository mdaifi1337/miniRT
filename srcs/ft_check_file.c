/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:13:40 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/07 18:14:17 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

/*
** not sure if i should check spaces, but i'll keep it for now
*/

static int	ft_check_spaces(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((tab[i] == '\t' || tab[i] == '\r' || tab[i] == '\f'
		|| tab[i] == '\v'))
		{
			write(1, "Error, invalid spaces...!\n", 27);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_check_values(char **tab, int i, int j)
{
	if (!ft_check_spaces(tab[i]))
		return (0);
	if (tab[i][j] == 'l' && tab[i][j + 1] == ' ')
		if (!ft_check_light(tab[i]))
			return (0);
	if (tab[i][j] == 'p' && tab[i][j + 1] == 'l')
		if (!ft_check_plane(tab[i]))
			return (0);
	if (tab[i][j] == 's' && tab[i][j + 1] == 'p')
		if (!ft_check_sphere(tab[i]))
			return (0);
	if (tab[i][j] == 's' && tab[i][j + 1] == 'q')
		if (!ft_check_square(tab[i]))
			return (0);
	if (tab[i][j] == 'c' && tab[i][j + 1] == 'y')
		if (!ft_check_cylinder(tab[i]))
			return (0);
	if (tab[i][j] == 't' && tab[i][j + 1] == 'r')
		if (!ft_check_triangle(tab[i]))
			return (0);
	return (1);
}

int			ft_check_file(t_env *e, char **tab)
{
	int i;
	int	j;

	i = 0;
	if (!ft_check_resolution(e, tab) || !ft_check_ambient(e, tab)
		|| !ft_check_cam(e, tab))
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] == ' ')
			j++;
		if (!ft_check_values(tab, i, j))
			return (0);
		i++;
	}
	return (1);
}
