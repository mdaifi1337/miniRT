/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:45:02 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/22 18:17:03 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

t_light		*ft_new_light(char *str)
{
	char		**tab;
	char		**temp;
	t_light		*light;

	tab = NULL;
	temp = NULL;
	light = (t_light *)malloc(sizeof(t_light));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[4], ',');
	light->trans = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[1], ',');
	light->pos = ft_make_vector(ft_atof(temp[0]) + light->trans.x,
				ft_atof(temp[1]) + light->trans.y,
				ft_atof(temp[2]) + light->trans.z);
	double_free(temp);
	light->intensity = ft_atof(tab[2]);
	temp = ft_split(tab[3], ',');
	light->color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	light->next = NULL;
	double_free(temp);
	double_free(tab);
	return (light);
}

t_Alight	ft_new_ambient(char *str)
{
	char		**tab;
	char		**temp;
	t_Alight	ambient;

	tab = NULL;
	temp = NULL;
	tab = ft_split(str, ' ');
	ambient.intensity = ft_atof(tab[1]);
	temp = ft_split(tab[2], ',');
	ambient.color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
					ft_atof(temp[2])};
	double_free(temp);
	double_free(tab);
	return (ambient);
}

void	ft_add_light(t_light **list, char *str)
{
	t_light *it_list;

	it_list = (*list);
	if (*list == NULL)
		(*list) = ft_new_light(str);
	else 
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = ft_new_light(str);
	}
}

void	ft_light(t_env *e, t_scene *object, t_scene *head, t_light *lights)
{
	t_vector		tmp;
	t_Alight		ambient;
	t_light			*light;

	init_phong(e);
	tmp = e->ray.dir;
	light = lights;
	ambient = ft_ambient(object, e);
	while (light != NULL)
	{
		light->dist_to_light = ft_vector_sub(light->pos, object->intersect_point);
		e->distance = getNorm(light->dist_to_light);
		light->dist_to_light = getNormalized(light->dist_to_light);
		e->ray.start = object->intersect_point;
		e->ray.dir = light->dist_to_light;
		if (!ft_shadow_cast(e, head))
		{
			ft_diffuse(object, e, light);
			ft_specular(object, e, light, tmp);
		}
		light = light->next;
	}
	final_color(e, &ambient);
}