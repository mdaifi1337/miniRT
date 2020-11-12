/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:19:05 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/06 18:54:26 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	ft_add_sphere(t_env *e, char *str)
{
	t_sphere	*sphere;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))) ||
		!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return ;
	sphere = ft_new_sphere(str);
	object->object = (void *)sphere;
	object->type = Tsphere;
	object->color = sphere->color;
	object->next = NULL;
	if (e->scene_head == NULL)
		e->scene_head = object;
	else
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = object;
	}
}

void	ft_add_plane(t_env *e, char *str)
{
	t_plane		*plane;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))) ||
		!(plane = (t_plane *)malloc(sizeof(t_plane))))
		return ;
	plane = ft_new_plane(str);
	object->object = (void *)plane;
	object->type = Tplane;
	object->color = plane->color;
	object->next = NULL;
	if (e->scene_head == NULL)
		e->scene_head = object;
	else
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = object;
	}
}

void	ft_add_cylinder(t_env *e, char *str)
{
	t_cylinder	*cylinder;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))) ||
		!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return ;
	cylinder = ft_new_cylinder(str);
	cylinder->normal = ft_rot(cylinder->normal, ft_rad(cylinder->rot.x),
					ft_rad(cylinder->rot.y), ft_rad(cylinder->rot.z));
	object->object = (void *)cylinder;
	object->type = Tcylinder;
	object->color = cylinder->color;
	object->next = NULL;
	if (e->scene_head == NULL)
		e->scene_head = object;
	else
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = object;
	}
}

void	ft_add_square(t_env *e, char *str)
{
	t_square	*square;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))) ||
		!(square = (t_square *)malloc(sizeof(t_square))))
		return ;
	square = ft_new_square(str);
	square->normal = ft_rot(square->normal, ft_rad(square->rot.x),
					ft_rad(square->rot.y), ft_rad(square->rot.z));
	object->object = (void *)square;
	object->type = Tsquare;
	object->color = square->color;
	object->next = NULL;
	if (e->scene_head == NULL)
		e->scene_head = object;
	else
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = object;
	}
}

void	ft_add_triangle(t_env *e, char *str)
{
	t_triangle	*triangle;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))) ||
		!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		return ;
	triangle = ft_new_triangle(str);
	object->object = (void *)triangle;
	object->type = Ttriangle;
	object->color = triangle->color;
	object->next = NULL;
	if (e->scene_head == NULL)
		e->scene_head = object;
	else
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = object;
	}
}
