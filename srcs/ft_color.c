/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:02:44 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/26 17:43:45 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_alight	ft_ambient(t_scene *scene, t_env *e)
{
	t_alight		ambient;

	ambient.color = (t_color){0, 0, 0};
	ambient.color.red += e->ambient.intensity * (e->ambient.color.red / 255)
						* (scene->color.red / 255);
	ambient.color.green += e->ambient.intensity * (e->ambient.color.green / 255)
						* (scene->color.green / 255);
	ambient.color.blue += e->ambient.intensity * (e->ambient.color.blue / 255)
						* (scene->color.blue / 255);
	return (ambient);
}

void		ft_specular(t_scene *scene, t_env *e, t_light *list, t_vector tmp)
{
	int			n;
	double		r;
	double		term;
	t_vector	reflection;
	t_vector	res;

	n = 60;
	r = 2.0 * ft_vector_dot(list->dist_to_light, scene->normal);
	reflection = vector_scale(r, scene->normal);
	res = get_normalized(ft_vector_sub(list->dist_to_light, reflection));
	term = pow(fmax(0.0f, ft_vector_dot(tmp, res)), n);
	e->specular.red += list->intensity * (list->color.red / 255) * term;
	e->specular.green += list->intensity * (list->color.green / 255) * term;
	e->specular.blue += list->intensity * (list->color.blue / 255) * term;
}

void		ft_diffuse(t_scene *scene, t_env *e, t_light *light)
{
	double	lambert;

	lambert = fmax(0.0, ft_vector_dot(light->dist_to_light, scene->normal));
	e->diffuse.red += (scene->color.red / 255) * (light->color.red / 255)
					* lambert * light->intensity;
	e->diffuse.green += (scene->color.green / 255) * (light->color.green / 255)
					* lambert * light->intensity;
	e->diffuse.blue += (scene->color.blue / 255) * (light->color.blue / 255)
					* lambert * light->intensity;
}

void		final_color(t_env *e, t_alight *ambient)
{
	e->phong.red = ambient->color.red + e->specular.red + e->diffuse.red;
	e->phong.green = ambient->color.green + e->specular.green
					+ e->diffuse.green;
	e->phong.blue = ambient->color.blue + e->specular.blue + e->diffuse.blue;
	clamp_colors(&e->phong, 0, 1);
}

int			get_int(t_color clr)
{
	char color[4];

	color[0] = clr.blue * 255;
	color[1] = clr.green * 255;
	color[2] = clr.red * 255;
	color[3] = 0;
	return (*(int *)color);
}
