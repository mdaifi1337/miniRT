/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:24:54 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 20:26:43 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*tmp;

	i = -1;
	j = 0;
	if (!s)
		return (ft_strdup(""));
	if ((tmp = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (s[++i])
		{
			if (i == start)
			{
				while (j < len)
					tmp[j++] = s[i++];
				tmp[j] = '\0';
				return (tmp);
			}
		}
	}
	return (NULL);
}
