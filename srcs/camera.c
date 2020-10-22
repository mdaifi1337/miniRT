/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:40:37 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/22 19:39:52 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

void	camera(t_env *e)
{
	t_vector	middle_point;

	middle_point = ft_vector_add(e->cam.pos, e->cam.look_at_point);
	e->cam.right = cross_product(&e->cam.default_up, &e->cam.look_at_point);
	e->cam.Up = cross_product(&e->cam.look_at_point, &e->cam.right);
	e->cam.HalfWidth = tan(e->cam.fov / 2);
	e->cam.aspectRatio = (double)e->HEIGHT / (double)e->WIDTH;
	e->cam.HalfHeight= e->cam.aspectRatio * e->cam.HalfWidth;
	e->cam.BottomLeftPoint = ft_vector_sub(ft_vector_sub(middle_point,
	vectorScale(e->cam.HalfWidth, e->cam.right)),
	vectorScale(e->cam.HalfHeight, e->cam.Up));
	e->cam.x_inc = vectorScale(2 * e->cam.HalfWidth, e->cam.right);
	e->cam.y_inc = vectorScale(2 * e->cam.HalfHeight, e->cam.Up);
}

void	ft_make_ray(t_env *e, int x, int y)
{
	t_vector viewPlanePoint;

	e->distance = RAY_DIS_MAX;
	viewPlanePoint = ft_vector_add(ft_vector_add(e->cam.BottomLeftPoint,
	vectorScale((double)x / e->WIDTH, e->cam.x_inc)),
	vectorScale((double)y / e->HEIGHT, e->cam.y_inc));
	e->ray.start = e->cam.pos;
	e->ray.dir = getNormalized(ft_vector_sub(viewPlanePoint, e->cam.pos));
}

t_camera	*ft_new_camera(char *str)
{
	char		**tab;
	char		**tmp;
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	tab = ft_split(str, ' ');
	tmp = ft_split(tab[4], ',');
	cam->trans = ft_make_vector(ft_atof(tmp[0]), ft_atof(tmp[1]),
				ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(tab[5], ',');
	cam->rot = ft_make_vector(ft_atof(tmp[0]), ft_atof(tmp[1]),
				ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(tab[1], ',');
	cam->pos = ft_make_vector(ft_atof(tmp[0]) + cam->trans.x,
				ft_atof(tmp[1]) + cam->trans.y,
				ft_atof(tmp[2]) + cam->trans.z);
	double_free(tmp);
	tmp = ft_split(tab[2], ',');
	cam->look_at_point = ft_make_vector(ft_atof(tmp[0]), ft_atof(tmp[1]),
				ft_atof(tmp[2]));
	cam->look_at_point = ft_rot(cam->look_at_point, ft_radians(cam->rot.x),
				ft_radians(cam->rot.y),
				ft_radians(cam->rot.z));
	double_free(tmp);
	cam->fov = ft_radians(ft_atof(tab[3]));
	double_free(tab);
	cam->default_up = (t_vector){0, 1, 0};
	return (cam);
}

static int	ft_it_cam_array(t_env *e, char **str)
{
	char	**tab;
	char	**temp;
	int		i;
	int		res;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == 'c' && str[i][1] == ' ')
		{
			e->cam.found++;
			tab = ft_split(str[i], ' ');
			if (ft_check_commas(tab) == -1)
				return (ft_free_error(tab));
			if (ft_check_nbr(tab, "Error, Invalid Camera value(s)..\n", 6) == -1)
				return (-1);
			temp = ft_split(tab[1], ',');
			if (ft_check_vector(temp, "Error, Invalid Camera position..\n") == -1)
				return (ft_free_error(tab));
			double_free(temp);
			temp = ft_split(tab[2], ',');
			if (ft_check_normal(temp, "Error, Invalid Camera orientation..\n") == -1)
				return (ft_free_error(tab));
			double_free(temp);
			if (ft_check_int_between(tab[3], "Error, Invalid FOV..\n", 0, 180) == -1)
				return (ft_free_error(tab));
			if (ft_check_trans(tab[4]) == -1)
				return (ft_free_error(tab));
			if (ft_check_rot(tab[5]) == -1)
				return (ft_free_error(tab));
			double_free(tab);
		}
	}
	res = i = 0 ? -1 : 1;
	return (res);
}

int		ft_check_camera(t_env *e, char **str)
{
	int	ret;

	ret = 1;
	ret = ft_it_cam_array(e, str);
	if (e->cam.found == 0)
	{
		write(1, "Error, Camera not found !..\n", 29);
		return (-1);
	}
	return (ret);
}

void	ft_add_cam(t_camera **list, char *str)
{
	t_camera	*it_list;
	t_camera	*new;
	
	new = ft_new_camera(str);
	if (*list == NULL)
	{
		(*list) = new;
		it_list = (*list);
	}
	else
	{
		it_list->next = new;
		it_list = new;
	}
	it_list->next = (*list);
}