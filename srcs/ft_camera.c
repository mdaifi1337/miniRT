/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:40:37 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/10 11:20:43 by mdaifi           ###   ########.fr       */
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

t_camera	*ft_new_camera(char *str)
{
	char		**tab;
	char		**tmp;
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	tab = ft_split(str, ' ');
	tmp = ft_split(tab[4], ',');
	cam->trs = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	tmp = ft_split(tab[5], ',');
	cam->rot = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
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
	return (cam);
}

static int	ft_check_cam_params(char *str)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (!ft_check_nbr(str, "Missing or extra camera value(s)!..\n", 6, ' '))
		return (ft_free_error(tab));
	if (!ft_check_vector(tab[1], "Invalid Camera position..\n", ','))
		return (ft_free_error(tab));
	if (!ft_check_normal(tab[2], "Invalid Camera orientation..\n"))
		return (ft_free_error(tab));
	if (!ft_check_int_between(tab[3], "Invalid FOV..\n", 0, 180))
		return (ft_free_error(tab));
	if (!ft_check_trans(tab[4], "Invalid camera transition..\n"))
		return (ft_free_error(tab));
	if (!ft_check_rot(tab[5], "Invalid camera rotation..\n"))
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
			if (e->curr_cam.found == 0)
			{
				write(1, "Camera not found !..\n", 22);
				return (0);
			}
			if (!ft_check_cam_params(str[i]))
				return (0);
		}
	}
	res = i == 0 ? 0 : 1;
	return (res);
}

void		ft_add_cam(t_env *e, char *str)
{
	t_camera	*it_list;

	it_list = e->cam_list;
	e->it_cam = e->cam_list;
	if (e->cam_list == NULL)
	{
		e->cam_list = ft_new_camera(str);
		e->curr_cam = *(e->cam_list);
	}
	else
	{
		while (it_list->next != NULL)
			it_list = it_list->next;
		it_list->next = ft_new_camera(str);
	}
}
