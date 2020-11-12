/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:38:18 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/05 18:39:10 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	ft_check_plane(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, "Missing or extra plane value(s)!..\n", 6, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Invalid Plane position..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_normal(tab[2], "Invalid Plane normal..\n"))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[3], "Invalid Plane color value(s)..\n"))
		return (ft_free_error(tab));
	if (!ft_check_trans(tab[4], "Invalid plane transition..\n"))
		return (ft_free_error(tab));
	if (!ft_check_rot(tab[5], "Invalid plane rotation..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int	ft_check_sphere(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, "Missing or extra sphere value(s)!..\n", 5, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Invalid Sphere position..\n", ','))
		return (ft_free_error(tab));
	if (!ft_between(tab[2], "Invalid Sphere radius..\n", 0, 2147483647))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[3], "Invalid Sphere color value(s)..\n"))
		return (ft_free_error(tab));
	if (!ft_check_trans(tab[4], "Invalid sphere transition..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int	ft_check_square(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, "Missing or extra square value(s)!..\n", 7, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Invalid Square position..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_normal(tab[2], "Invalid Square normal..\n"))
		return (ft_free_error(tab));
	if (!ft_between(tab[3], "Invalid Square side..\n", 0, INT_MAX))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[4], "Invalid Square color value(s)..\n"))
		return (ft_free_error(tab));
	if (!ft_check_trans(tab[5], "Invalid square transition..\n"))
		return (ft_free_error(tab));
	if (!ft_check_rot(tab[6], "Invalid square rotation..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int	ft_check_cylinder(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, "Missing or extra cylinder value(s)!..\n", 8, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Invalid Cylinder position..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_normal(tab[2], "Invalid Cylinder normal..\n"))
		return (ft_free_error(tab));
	if (!ft_between(tab[3], "Invalid Cylinder diameter..\n", 0, INT_MAX))
		return (ft_free_error(tab));
	if (!ft_between(tab[4], "Invalid Cylinder height..\n", 0, INT_MAX))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[5], "Invalid Cylinder color value(s)..\n"))
		return (ft_free_error(tab));
	if (!ft_check_trans(tab[6], "Invalid cylinder transition..\n"))
		return (ft_free_error(tab));
	if (!ft_check_rot(tab[7], "Invalid cylinder rotation..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int	ft_check_triangle(char *str)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, "Missing or extra triangle value(s)!..\n", 5, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Invalid Triangle first point..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[2], "Invalid Triangle second point..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[3], "Invalid Triangle third point..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_color(tab[4], "Invalid Triangle color value(s)..\n"))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}
