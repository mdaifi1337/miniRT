/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:09:46 by mdaifi            #+#    #+#             */
/*   Updated: 2019/10/27 21:57:31 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if ((tmp = (char *)malloc(count * size)))
	{
		while (i < count * size)
		{
			tmp[i] = 0;
			i++;
		}
		return ((void*)tmp);
	}
	return (NULL);
}
