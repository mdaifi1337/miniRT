/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:38:18 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 17:13:35 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int	ft_check_plane(char *str)
{
	char	**tab;
	char	**temp;

	tab = NULL;
	temp = NULL;
	tab = ft_split(str, ' ');
	if (ft_check_commas(tab) == -1)
		return (ft_free_error(tab));
	if (ft_check_nbr(tab, "Error, Invalid Plane value(s)..\n", 4) == -1)
        return (-1);
	temp = ft_split(tab[1], ',');
	if (ft_check_vector(temp, "Error, Invalid Plane position..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	if (ft_check_normal(temp, "Error, Invalid Plane normal..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	temp = ft_split(tab[3], ',');
	if (ft_check_color(temp, "Error, Invalid Plane color value(s)..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	double_free(tab);
	return (1);
}

int	ft_check_sphere(char *str)
{
	char	**tab;
	char	**temp;

	tab = NULL;
	temp = NULL;
	tab = ft_split(str, ' ');
	if (ft_check_commas(tab) == -1)
		return (ft_free_error(tab));
	if (ft_check_nbr(tab, "Error, Invalid Sphere value(s)..\n", 4) == -1)
        return (-1);
	temp = ft_split(tab[1], ',');
	if (ft_check_vector(temp, "Error, Invalid Sphere position..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	if (ft_check_between(tab[2], "Error, Invalid Sphere radius..\n", 0, 2147483647) == -1)
		return (ft_free_error(tab));
	temp = ft_split(tab[3], ',');
	if (ft_check_color(temp, "Error, Invalid Sphere color value(s)..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	double_free(tab);
	return (1);
}

int	ft_check_square(char *str)
{
	char	**tab;
	char	**temp;

	tab = NULL;
	temp = NULL;
	tab = ft_split(str, ' ');
	if (ft_check_commas(tab) == -1)
		return (ft_free_error(tab));
	if (ft_check_nbr(tab, "Error, Missing or extra Square value(s) !..\n", 5) == -1)
        return (-1);
	temp = ft_split(tab[1], ',');
	if (ft_check_vector(temp, "Error, Invalid Square position..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	if (ft_check_normal(temp, "Error, Invalid Square normal..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	if (ft_check_between(tab[3], "Error, Invalid Square side..\n", 0, INT_MAX) == -1)
		return (ft_free_error(tab));
	temp = ft_split(tab[4], ',');
	if (ft_check_color(temp, "Error, Invalid Square color value(s)..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	double_free(tab);
	return (1);
}

int	ft_check_cylinder(char *str)
{
	char	**tab;
	char	**temp;

	tab = NULL;
	temp = NULL;
	tab = ft_split(str, ' ');
	if (ft_check_commas(tab) == -1)
		return (ft_free_error(tab));
	if (ft_check_nbr(tab, "Error, Invalid Cylinder value(s) !..\n", 6) == -1)
        return (-1);
	temp = ft_split(tab[1], ',');
	if (ft_check_vector(temp, "Error, Invalid Cylinder position..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	if (ft_check_normal(temp, "Error, Invalid Cylinder normal..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	if (ft_check_between(tab[3], "Error, Invalid Cylinder diameter..\n", 0, INT_MAX) == -1)
		return (ft_free_error(tab));
	if (ft_check_between(tab[4], "Error, Invalid Cylinder height..\n", 0, INT_MAX) == -1)
		return (ft_free_error(tab));
	temp = ft_split(tab[5], ',');
	if (ft_check_color(temp, "Error, Invalid Cylinder color value(s)..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	double_free(tab);
	return (1);
}

int	ft_check_triangle(char *str)
{
	char	**tab;
	char	**temp;

	tab = NULL;
	temp = NULL;
	tab = ft_split(str, ' ');
	if (ft_check_commas(tab) == -1)
		return (ft_free_error(tab));
	if (ft_check_nbr(tab, "Error, Invalid Triangle value(s) !..\n", 5) == -1)
        return (-1);
	temp = ft_split(tab[1], ',');
	if (ft_check_vector(temp, "Error, Invalid Triangle first point..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	if (ft_check_vector(temp, "Error, Invalid Triangle second point..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	temp = ft_split(tab[3], ',');
	if (ft_check_vector(temp, "Error, Invalid Triangle third point..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	temp = ft_split(tab[4], ',');
	if (ft_check_color(temp, "Error, Invalid Triangle color value(s)..\n") == -1)
		return (ft_free_error(tab));
	double_free(temp);
	double_free(tab);
	return (1);
}