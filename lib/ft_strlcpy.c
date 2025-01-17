/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:43:17 by mdaifi            #+#    #+#             */
/*   Updated: 2019/10/27 21:45:18 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	char		*ch1;
	char		*ch2;

	ch1 = dst;
	ch2 = src;
	if (!dst)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (*ch2 != '\0')
	{
		if (size != 1)
		{
			*ch1++ = *ch2;
			size--;
		}
		ch2++;
	}
	*ch1 = '\0';
	return ((ch2 - src));
}
