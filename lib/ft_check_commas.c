/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:23:09 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/26 13:32:21 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_commas(char *tab)
{
	char	**tmp;
	int		i;
	int		j;
	int		c;

	i = 0;
	tmp = ft_split(tab, ' ');
	while (tmp[i])
	{
		c = 0;
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == ',')
				c++;
			j++;
		}
		if (c > 2)
		{
			write(1, "Check number of commas..!\n", 27);
			return (0);
		}
		i++;
	}
	return (1);
}
