/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:13:40 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 15:30:36 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

static int	ft_check_spaces(char *tab) // not sure if i should check this, but i'll keep it for now
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '\t' || tab[i] == '\r' || tab[i] == '\f' || tab[i] == '\v')
		{
			write(1, "Error, invalid spaces...!\n", 27);
			return (-1);
		}
		i++;
	}
	return (1);
}

int    ft_check_file(t_env *e, char **tab)
{
    int i;
	int	j;
    int ret;

    i = 0;
    ret = 1;
    if (ft_check_resolution(e, tab) == -1 ||
    	ft_check_ambient(e, tab) == -1 ||
    	ft_check_camera(e, tab) == -1)
        return (-1);
    while (tab[i])
    {
		j = 0;
		while(tab[i][j] == ' ')
			j++;
		if(ft_check_spaces(tab[i]) == -1)
			return (-1);
		if (tab[i][j] == 'l')
            if (ft_check_light(tab[i]) == -1)
				return (-1);
		if (tab[i][j] == 'p' && tab[i][j + 1] == 'l')
			if (ft_check_plane(tab[i]) == -1)
				return (-1);
		if (tab[i][j] == 's' && tab[i][j + 1] == 'p')
			if (ft_check_sphere(tab[i]) == -1)
				return (-1);
		if (tab[i][j] == 's' && tab[i][j + 1] == 'q')
			if (ft_check_square(tab[i]) == -1)
				return (-1);
		if (tab[i][j] == 'c' && tab[i][j + 1] == 'y')
			if (ft_check_cylinder(tab[i]) == -1)
				return (-1);
		if (tab[i][j] == 't' && tab[i][j + 1] == 'r')
			if (ft_check_triangle(tab[i]) == -1)
				return (-1);
        i++;
    }
    return (ret);
}