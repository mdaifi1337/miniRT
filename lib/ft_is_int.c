/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:20:14 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/26 13:31:35 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_int(char *str, char *ch)
{
	int i;

	i = 0;
	if (str[0] == '-' && ft_strlen(str) < 1)
		return (-1);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(1, ch, ft_strlen(ch));
			return (0);
		}
		i++;
	}
	return (1);
}
