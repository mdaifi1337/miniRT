/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:16:44 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/26 13:31:49 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_double(char *str, int i, char *ch)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			count++;
		}
		if (!ft_isdigit(str[i]) || count > 1)
		{
			write(1, ch, ft_strlen(ch));
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_double(char *str, char *ch)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if ((str[0] == '.' || str[ft_strlen(str)] == '.')
		|| (str[0] == '-' && ft_strlen(str) == 1))
	{
		write(1, ch, ft_strlen(ch));
		return (0);
	}
	if (str[0] == '-')
		i++;
	if (!ft_double(str, i, ch))
		return (0);
	return (1);
}
