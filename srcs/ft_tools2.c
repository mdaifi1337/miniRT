/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:20:30 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/28 17:18:37 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	clamp_colors(t_color *clr, int min, int max)
{
	clr->red = clr->red < min ? min : clr->red;
	clr->red = clr->red > max ? max : clr->red;
	clr->green = clr->green < min ? min : clr->green;
	clr->green = clr->green > max ? max : clr->green;
	clr->blue = clr->blue < min ? min : clr->blue;
	clr->blue = clr->blue > max ? max : clr->blue;
}

int		ft_smallest_value(t_env *e)
{
	if (((e->t2 < e->t1 || e->t1 < 0.0001) && e->t2 > 0.0001)
		&& e->t2 < e->distance)
	{
		e->distance = e->t2;
		return (1);
	}
	else if (((e->t1 < e->t2 || e->t2 < 0.0001) && e->t1 > 0.0001)
		&& e->t1 < e->distance)
	{
		e->distance = e->t1;
		return (1);
	}
	else
		return (0);
}

int		ft_found(char *str, char *ch, int j)
{
	if (!ft_strncmp(str + j, ch, ft_strlen(ch)))
		return (1);
	return (0);
}

void		ft_free_strings(char **scene, char *str)
{
	free(str);
	double_free(scene);
}
