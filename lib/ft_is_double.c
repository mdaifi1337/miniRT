/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:48:24 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/11 18:17:02 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int ft_is_double(char *str, char *ch)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if ((str[0] == '.' || str[ft_strlen(str)] == '.') 
        || (str[0] == '-' && ft_strlen(str) == 1))
    {
        write(1, ch, ft_strlen(ch));
        return (-1);
    }
    if (str[0] == '-')
        i++;
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
            return (-1);
        }
        i++;
    }
    return (1);
}