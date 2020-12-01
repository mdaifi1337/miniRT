/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:40:37 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/28 20:48:10 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void		camera(t_env *e)
{
	t_vector	middle_point;

	middle_point = ft_vector_add(e->curr_cam.pos, e->curr_cam.look_at);
	e->curr_cam.right = get_normalized(cross_product(&e->curr_cam.default_up,
						&e->curr_cam.look_at));
	e->curr_cam.up = get_normalized(cross_product(&e->curr_cam.look_at,
					&e->curr_cam.right));
	e->curr_cam.halfwidth = tan(e->curr_cam.fov / 2);
	e->curr_cam.aspectratio = (double)e->height / (double)e->width;
	e->curr_cam.halfheight = e->curr_cam.aspectratio * e->curr_cam.halfwidth;
	e->curr_cam.bottomleftpoint = ft_vector_sub(ft_vector_sub(middle_point,
	vector_scale(e->curr_cam.halfwidth, e->curr_cam.right)),
	vector_scale(e->curr_cam.halfheight, e->curr_cam.up));
	e->curr_cam.x_inc = vector_scale(2 * e->curr_cam.halfwidth,
						e->curr_cam.right);
	e->curr_cam.y_inc = vector_scale(2 * e->curr_cam.halfheight,
		e->curr_cam.up);
}

t_camera	*ft_new_camera(char **str, int *i)
{
	char		**tab;
	char		**tmp;
	t_camera	*cam;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	tab = ft_split(str[*i], ' ');
	cam->rot = (t_vector){0, 0, 0};
	cam->trs = ft_trs_and_rot(str,
			"Error\nInvalid camera translation(s) or rotation(s) !..\n", i,
			&cam->rot);
	tmp = ft_split(tab[1], ',');
	cam->pos = (t_vector){ft_atof(tmp[0]) + cam->trs.x,
				ft_atof(tmp[1]) + cam->trs.y, ft_atof(tmp[2]) + cam->trs.z};
	double_free(tmp);
	tmp = ft_split(tab[2], ',');
	cam->look_at = ft_rot((t_vector){ft_atof(tmp[0]) + 0.0001, ft_atof(tmp[1]),
				ft_atof(tmp[2])}, ft_rad(cam->rot.x), ft_rad(cam->rot.y),
				ft_rad(cam->rot.z));
	double_free(tmp);
	cam->fov = ft_rad(ft_atof(tab[3]));
	double_free(tab);
	cam->default_up = (t_vector){0, 1, 0};
	cam->next = NULL;
	return (cam);
}

static int	ft_check_cam_params(char *str)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, "Error\nMissing or extra camera value(s) !..\n",
		4, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Error\nInvalid Camera position !..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_normal(tab[2], "Error\nInvalid Camera orientation !..\n"))
		return (ft_free_error(tab));
	if (!ft_check_int_between(tab[3], "Error\nInvalid camera FOV !..\n",
		0, 180))
		return (ft_free_error(tab));
	double_free(tab);
	return (1);
}

int			ft_check_cam(t_env *e, char **str)
{
	int		i;
	int		res;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == 'c' && str[i][1] == ' ')
		{
			e->curr_cam.found = 1;
			if (!ft_check_cam_params(str[i]))
				return (0);
		}
	}
	if (e->curr_cam.found == 0)
	{
		write(1, "Error\nCamera not found !..\n", 28);
		return (0);
	}
	res = i == 0 ? 0 : 1;
	return (res);
}

void		ft_add_cam(t_env *e, char **str, int *i)
{
	t_camera	*it_list;

	it_list = e->cam_list;
	if (e->cam_list == NULL)
	{
		e->cam_list = ft_new_camera(str, i);
		e->it_cam = e->cam_list;
		e->curr_cam = *(e->cam_list);
	}
	else
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = ft_new_camera(str, i);
	}
}
