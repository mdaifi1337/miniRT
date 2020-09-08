/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:41:42 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 17:17:57 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int	ft_check_vector(char **tab, char *str)
{
	if (ft_check_nbr(tab, str, 3) == -1 ||
		ft_check_tab_double(tab, str) == -1)
		return (-1);
	return (1);
}

int	ft_check_between(char *tab, char *str, double min, double max)
{
	if (ft_is_double(tab, str) == -1 ||
		ft_is_between(ft_atof(tab), min, max, str) == -1)
		return (-1);
	return (1);
}

int	ft_check_color(char **tab, char *str)
{
	if (ft_check_nbr(tab, str, 3) == -1 ||
		ft_check_tab_int(tab, str) == -1 ||
		ft_check_tab_between(tab, 0, 255, str) == -1)
		return (-1);
	return (1);
}

int	ft_check_normal(char **tab, char *str)
{
	if (ft_check_nbr(tab, str, 3) == -1 ||
		ft_check_tab_double(tab, str) == -1 ||
		ft_check_tab_between(tab, -1, 1, str) == -1)
		return (-1);
	return (1);
}

int	ft_check_int_between(char *tab, char *str, int min, int max)
{
	if (ft_is_int(tab, str) == -1 ||
		ft_is_between(ft_atof(tab), min, max, str) == -1)
		return (-1);
	return (1);
}