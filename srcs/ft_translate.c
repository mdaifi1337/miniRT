/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:41:24 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/26 13:27:51 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

/*
** re-check for leaks (ft_free_error(tmp))
*/

int			ft_check_trans(char *str, char *ch)
{
	if (!ft_check_vector(str, ch, ','))
		return (0);
	return (1);
}

t_vector	ft_add_trs(char *str)
{
	t_vector	res;
	char		**tmp;

	tmp = ft_split(str, ',');
	res = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	return (res);
}
