/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:42:21 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 19:43:31 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

t_sphere	*ft_new_sphere(char *str)
{
	char		**tab;
	char		**temp;
	t_sphere	*sphere;

	tab = NULL;
	temp = NULL;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[1], ',');
	sphere->pos = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	sphere->radius = ft_atof(tab[2]) / 2;
	double_free(temp);
	temp = ft_split(tab[3], ',');
	sphere->color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	double_free(tab);
	return (sphere);
}

t_plane		*ft_new_plane(char *str)
{
	char		**tab;
	char		**temp;
	t_plane		*plane;

	tab = NULL;
	temp = NULL;
	plane = (t_plane *)malloc(sizeof(t_plane));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[1], ',');
	plane->pos = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	plane->normal = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[3], ',');
	plane->color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	double_free(tab);
	return (plane);
}

t_cylinder	*ft_new_cylinder(char *str)
{
	char		**tab;
	char		**temp;
	t_cylinder	*cylinder;

	tab = NULL;
	temp = NULL;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[1], ',');
	cylinder->pos = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	cylinder->normal = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	cylinder->width = ft_atof(tab[3]);
	cylinder->height = ft_atof(tab[4]);
	temp = ft_split(tab[5], ',');
	cylinder->color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	double_free(tab);
	return (cylinder);
}

t_square	*ft_new_square(char *str)
{
	char		**tab;
	char		**temp;
	t_square	*square;

	tab = NULL;
	temp = NULL;
	square = (t_square *)malloc(sizeof(t_square));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[1], ',');
	square->pos = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	square->normal = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	square->side = ft_atof(tab[3]);
	temp = ft_split(tab[4], ',');
	square->color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	double_free(tab);
	return (square);
}

t_triangle	*ft_new_triangle(char *str)
{
	char		**tab;
	char		**temp;
	t_triangle	*triangle;

	tab = NULL;
	temp = NULL;
	triangle = (t_triangle *)malloc(sizeof(t_triangle));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[1], ',');
	triangle->point_a = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	triangle->point_b = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[3], ',');
	triangle->point_c = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[4], ',');
	triangle->color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	double_free(tab);
	return (triangle);
}