/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:40:37 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/13 18:38:41 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

void	camera(t_env *e, t_vector look_at, float fov, unsigned int xRes,
		unsigned int yRes)
{
	t_vector	middle_point;

	middle_point = ft_vector_add(e->cam.pos, look_at);
	e->cam.right = cross_product(&e->cam.default_up, &look_at);
	e->cam.Up = cross_product(&look_at, &e->cam.right);
	e->cam.HalfWidth = tan(fov / 2);
	e->cam.aspectRatio = (double)yRes / (double)xRes;
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

t_camera	ft_new_camera(char *str)
{
	char		**tab;
	char		**tmp;
	t_camera	camera;

	tab = ft_split(str, ' ');
	tmp = ft_split(tab[1], ',');
	camera.pos = ft_make_vector(ft_atof(tmp[0]), ft_atof(tmp[1]),
				ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(tab[2], ',');
	camera.look_at_point = ft_make_vector(ft_atof(tmp[0]), ft_atof(tmp[1]),
					ft_atof(tmp[2]));
	double_free(tmp);
	camera.fov = ft_radians(ft_atof(tab[3]));
	double_free(tab);
	return (camera);
}

int		ft_check_camera(t_env *e, char **str)
{
	char		**tab;
	char		**temp;
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == 'c' && str[i][1] == ' ')
		{
			e->cam.found++;
			tab = ft_split(str[i], ' ');
			if (ft_check_nbr(tab, "Error, Invalid Camera value(s)..\n", 4) == -1)
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
			double_free(tab);
		}
	}
	if (e->cam.found == 0)
	{
		write(1, "Error, Camera not found !..\n", 29);
		return (-1);
	}
	return (1);
}