/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_between.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:59:18 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/11 16:27:31 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int    ft_is_between(double n, int min, int max, char *str)
{
    if (n < min || n > max)
    {
        write(1, str, ft_strlen(str));
        return (-1);
    }
    return (1);
}