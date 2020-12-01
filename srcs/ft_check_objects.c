/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:38:18 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/25 17:20:50 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	ft_check_plane(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str,
		"Error\nMissing or extra plane value(s) !..\n", 4, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Error\nInvalid plane position !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_normal(tab[2], "Error\nInvalid plane normal !..\n"))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[3], "Error\nInvalid plane color value(s) !..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int	ft_check_sphere(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str,
		"Error\nMissing or extra sphere value(s) !..\n", 4, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Error\nInvalid sphere position !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_between(tab[2], "Error\nInvalid sphere radius !..\n", 0, INT_MAX))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[3], "Error\nInvalid sphere color value(s) !..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int	ft_check_square(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str,
		"Error\nMissing or extra square value(s) !..\n", 5, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Error\nInvalid square position !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_normal(tab[2], "Error\nInvalid square normal !..\n"))
		return (ft_free_error(tab));
	if (!ft_between(tab[3], "Error\nInvalid square side !..\n", 0, INT_MAX))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[4], "Error\nInvalid square color value(s) !..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int	ft_check_cylinder(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str,
		"Error\nMissing or extra cylinder value(s) !..\n", 6, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1],
		"Error\nInvalid cylinder position !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_normal(tab[2], "Error\nInvalid cylinder normal !..\n"))
		return (ft_free_error(tab));
	if (!ft_between(tab[3], "Error\nInvalid cylinder width !..\n", 0, INT_MAX))
		return (ft_free_error(tab));
	if (!ft_between(tab[4],
		"Error\nInvalid cylinder height !..\n", 0, INT_MAX))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[5],
		"Error\nInvalid cylinder color value(s) !..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int	ft_check_triangle(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str,
		"Error\nMissing or extra triangle value(s) !..\n", 5, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1],
		"Error\nInvalid triangle first point !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[2],
		"Error\nInvalid triangle second point !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[3],
		"Error\nInvalid triangle third point !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[4],
		"Error\nInvalid triangle color value(s) !..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}
