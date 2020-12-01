/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:19:05 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/29 17:41:13 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	ft_add_sphere(t_env *e, char **str, int *i)
{
	t_sphere	*sphere;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))))
		return ;
	sphere = ft_new_sphere(str, i);
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

void	ft_add_plane(t_env *e, char **str, int *i)
{
	t_plane		*plane;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))))
		return ;
	plane = ft_new_plane(str, i);
	plane->normal = ft_rot(plane->normal, ft_rad(plane->rot.x),
					ft_rad(plane->rot.z), ft_rad(plane->rot.y));
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

void	ft_add_cylinder(t_env *e, char **str, int *i)
{
	t_cylinder	*cylinder;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))))
		return ;
	cylinder = ft_new_cylinder(str, i);
	cylinder->normal = ft_rot(cylinder->normal, ft_rad(cylinder->rot.x),
					ft_rad(cylinder->rot.z), ft_rad(cylinder->rot.y));
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

void	ft_add_square(t_env *e, char **str, int *i)
{
	t_square	*square;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))))
		return ;
	square = ft_new_square(str, i);
	square->normal = ft_rot(square->normal, ft_rad(square->rot.x),
					ft_rad(square->rot.z), ft_rad(square->rot.y));
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

void	ft_add_triangle(t_env *e, char **str, int *i)
{
	t_triangle	*triangle;
	t_scene		*it_list;
	t_scene		*object;

	it_list = e->scene_head;
	if (!(object = (t_scene *)malloc(sizeof(t_scene))))
		return ;
	triangle = ft_new_triangle(str,
		"Error\nInvalid triangle translation(s) !..\n", i);
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
