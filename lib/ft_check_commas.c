/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:23:09 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/24 19:55:04 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_commas_error(char *str, int c)
{
	if (c > 2)
	{
		write(1, str, ft_strlen(str));
		return (0);
	}
	return (1);
}

int			ft_check_commas(char *str, char *tab)
{
	char	**tmp;
	int		i;
	int		j;
	int		c;

	i = -1;
	tmp = ft_split(tab, ' ');
	while (tmp[++i])
	{
		c = 0;
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == ',')
				c++;
			j++;
			if (!ft_commas_error(str, c))
				return (ft_free_error(tmp));
		}
	}
	double_free(tmp);
	return (1);
}
