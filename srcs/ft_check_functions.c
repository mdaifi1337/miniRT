/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:41:42 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/26 13:27:01 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int	ft_check_vector(char *tab, char *str, char c)
{
	if (!ft_check_nbr(tab, str, 3, c) ||
		!ft_check_tab_double(tab, str) || !ft_check_commas(tab))
		return (0);
	return (1);
}

int	ft_between(char *tab, char *str, double min, double max)
{
	if (!ft_is_double(tab, str) || !ft_is_between(ft_atof(tab), min, max, str))
		return (0);
	return (1);
}

int	ft_check_color(char *str, char *ch)
{
	if (!ft_check_nbr(str, ch, 3, ',') || !ft_check_tab_int(str, ch)
		|| !ft_check_tab_between(str, 0, 255, ch) || !ft_check_commas(str))
		return (0);
	return (1);
}

int	ft_check_normal(char *tab, char *str)
{
	if (!ft_check_nbr(tab, str, 3, ',') || !ft_check_tab_double(tab, str) ||
		!ft_check_tab_between(tab, -1, 1, str) || !ft_check_commas(tab))
		return (0);
	return (1);
}

int	ft_check_int_between(char *tab, char *str, int min, int max)
{
	if (!ft_is_int(tab, str) || !ft_is_between(ft_atof(tab), min, max, str))
		return (0);
	return (1);
}
