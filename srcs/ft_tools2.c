/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:20:30 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/10 11:33:26 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	ft_add_trs_and_rot(t_vector *trs, char *str1, t_vector *rot, char *str2)
{
	*trs = ft_add_trs(str1);
	*rot = ft_add_rot(str2);
}

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
