/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:45:02 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/28 19:07:26 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_light		*ft_new_light(char **str, int *i)
{
	char		**tab;
	char		**temp;
	t_light		*light;

	tab = NULL;
	temp = NULL;
	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	tab = ft_split(str[*i], ' ');
	light->trs = ft_trs_and_rot(str,
		"Error\nInvalid light transition!..\n", i, NULL);
	temp = ft_split(tab[1], ',');
	light->pos = ft_make_vector(ft_atof(temp[0]) + light->trs.x,
				ft_atof(temp[1]) + light->trs.y,
				ft_atof(temp[2]) + light->trs.z);
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

t_alight	ft_new_ambient(char *str)
{
	char		**tab;
	char		**temp;
	t_alight	ambient;

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

void		ft_add_light(t_light **list, char **str, int *i)
{
	t_light	*it_list;

	it_list = (*list);
	if (*list == NULL)
		(*list) = ft_new_light(str, i);
	else
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = ft_new_light(str, i);
	}
}

void		ft_light(t_env *e, t_scene *object, t_scene *head, t_light *lights)
{
	t_vector	tmp;
	t_alight	ambient;
	t_light		*light;

	init_phong(e);
	tmp = e->ray.dir;
	light = lights;
	ambient = ft_ambient(object, e);
	while (light != NULL)
	{
		light->dist_to_light = ft_vector_sub(light->pos, object->inter_point);
		e->distance = get_norm(light->dist_to_light);
		light->dist_to_light = get_normalized(light->dist_to_light);
		e->ray.start = object->inter_point;
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
