/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:31:48 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/11 21:26:24 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int ft_is_int(char *str, char *ch)
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
            return (-1);
        }
        i++;
    }
    return (1);
}