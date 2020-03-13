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

int    ft_check_file(t_env *e, char **tab)
{
    int i;
    int ret;

    i = 0;
    ret = 1;
    if (ft_check_resolution(e, tab) == -1 ||
    	ft_check_ambient(e, tab) == -1 ||
    	ft_check_camera(e, tab) == -1)
        return (-1);
    while (tab[i])
    {
		if (tab[i][0] == 'l')
            if (ft_check_light(tab[i]) == -1)
				return (-1);
		if (tab[i][0] == 'p' && tab[i][1] == 'l')
			if (ft_check_plane(tab[i]) == -1)
				return (-1);
		if (tab[i][0] == 's' && tab[i][1] == 'p')
			if (ft_check_sphere(tab[i]) == -1)
				return (-1);
		if (tab[i][0] == 's' && tab[i][1] == 'q')
			if (ft_check_square(tab[i]) == -1)
				return (-1);
		if (tab[i][0] == 'c' && tab[i][1] == 'y')
			if (ft_check_cylinder(tab[i]) == -1)
				return (-1);
		if (tab[i][0] == 't' && tab[i][1] == 'r')
			if (ft_check_triangle(tab[i]) == -1)
				return (-1);
        i++;
    }
    return (ret);
}