/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:02:44 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 16:44:16 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

t_Alight		ft_ambient(t_scene *scene, t_env *e)
{
	t_Alight		ambient;

	ambient.color = (t_color){0, 0, 0};
	ambient.color.red += e->ambient.intensity * (e->ambient.color.red / 255) * (scene->color.red / 255);
	ambient.color.green += e->ambient.intensity * (e->ambient.color.green / 255) * (scene->color.green / 255);
	ambient.color.blue += e->ambient.intensity * (e->ambient.color.blue / 255) * (scene->color.blue / 255);
	return (ambient);
}

void	ft_specular(t_scene *scene, t_env *e, t_light *list, t_vector tmp)
{
	int			N;
	t_vector	R;

	N = 60;
	R = ft_vector_sub(list->dist_to_light, vectorScale(2 * ft_vector_dot(list->dist_to_light, scene->normal), scene->normal));
	e->specular.red += list->intensity * (list->color.red / 255) * pow(max(0.0f, ft_vector_dot(tmp, R)), N);
	e->specular.green += list->intensity * (list->color.green / 255) * pow(max(0.0f, ft_vector_dot(tmp, R)), N);
	e->specular.blue += list->intensity * (list->color.blue / 255) * pow(max(0.0f, ft_vector_dot(tmp, R)), N);
}

void	ft_diffuse(t_scene *scene, t_env *e, t_light *light)
{
	double	lambert;

	lambert = max(0.0, ft_vector_dot(light->dist_to_light, scene->normal));
	e->diffuse.red += (scene->color.red / 255) * (light->color.red / 255) * lambert * light->intensity;
	e->diffuse.green += (scene->color.green / 255) * (light->color.green / 255) * lambert * light->intensity;
	e->diffuse.blue += (scene->color.blue / 255) * (light->color.blue / 255) * lambert * light->intensity;
}

void	final_color(t_env *e, t_Alight *ambient)
{
	e->phong.red = ambient->color.red + e->specular.red + e->diffuse.red;
	e->phong.green = ambient->color.green + e->specular.green
					+ e->diffuse.green;
	e->phong.blue = ambient->color.blue + e->specular.blue + e->diffuse.blue;
	clamp_colors(&e->phong, 0, 1);
}