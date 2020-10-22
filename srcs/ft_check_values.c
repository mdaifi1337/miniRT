/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:46:15 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/22 18:29:48 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

int    ft_check_nbr(char **tab, char *str, int nbr)
{
    int i;

    i = ft_count_table(tab);
    if (i != nbr)
    {
        write(1, str, ft_strlen(str));
        double_free(tab);
        return (-1);
    }
    return (1);
}

int    ft_check_tab_between(char **tab, int min, int max, char *str)
{
    int i;
    int nbr;

    i = 0;
    while (tab[i])
    {
        if (ft_is_between(ft_atof(tab[i]), min, max, str) == -1)
        {
            double_free(tab);
            return (-1);
        }
        i++;
    }
    return (1);
}

int    ft_check_tab_int(char **tab, char *str)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (ft_is_int(tab[i], str) == -1)
        {
            double_free(tab);
            return (-1);
        }
        i++;
    }
    return (1);
}

int    ft_check_tab_double(char **tab, char *str)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (ft_is_double(tab[i], str) == -1)
        {
            double_free(tab);
            return (-1);
        }
        i++;
    }
    return (1);
}	