/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:19:01 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/08 18:12:26 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	init_phong(t_env *e)
{
	e->diffuse = (t_color){0, 0, 0};
	e->specular = (t_color){0, 0, 0};
	e->phong = (t_color){0, 0, 0};
}

void	init_vars(t_env *e)
{
	e->cam_count = 1;
	e->curr_cam.found = 0;
	e->resolution = 0;
	e->ambient.found = 0;
}
