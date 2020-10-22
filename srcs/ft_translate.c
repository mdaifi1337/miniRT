/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:41:24 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/21 18:24:14 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int		ft_check_trans(char *str)
{
	char    **tmp;

	tmp = NULL;
	tmp = ft_split(str, ',');
	if (ft_check_vector(tmp, "Error, Invalid translation value(s)..\n") == -1)
		return (-1); // re-check for leaks (ft_free_error(tmp))
	double_free(tmp);
	return (1);
}