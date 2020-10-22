/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:42:21 by mdaifi            #+#    #+#             */
/*   Updated: 2020/10/22 17:48:02 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

t_sphere	*ft_new_sphere(t_env *e, char *str)
{
	char		**tab;
	char		**temp;
	t_sphere	*sphere;

	tab = NULL;
	temp = NULL;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[4], ',');
	sphere->trans = (t_vector){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	temp = ft_split(tab[1], ',');
	sphere->pos = ft_make_vector(ft_atof(temp[0]) + sphere->trans.x,
				ft_atof(temp[1]) + sphere->trans.y,
				ft_atof(temp[2]) + sphere->trans.z);
	sphere->radius = ft_atof(tab[2]);
	double_free(temp);
	temp = ft_split(tab[3], ',');
	sphere->color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	double_free(tab);
	return (sphere);
}

t_plane		*ft_new_plane(t_env *e, char *str)
{
	char		**tab;
	char		**temp;
	t_plane		*plane;

	tab = NULL;
	temp = NULL;
	plane = (t_plane *)malloc(sizeof(t_plane));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[4], ',');
	plane->trans = (t_vector){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	temp = ft_split(tab[5], ',');
	plane->rot = (t_vector){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	temp = ft_split(tab[1], ',');
	plane->pos = ft_make_vector(ft_atof(temp[0]) + plane->trans.x,
				ft_atof(temp[1]) + plane->trans.y,
				ft_atof(temp[2]) + plane->trans.z);
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

t_cylinder	*ft_new_cylinder(t_env *e, char *str)
{
	char		**tab;
	char		**temp;
	t_cylinder	*cylinder;

	tab = NULL;
	temp = NULL;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[6], ',');
	cylinder->trans = (t_vector){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	temp = ft_split(tab[7], ',');
	cylinder->rot = (t_vector){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	temp = ft_split(tab[1], ',');
	cylinder->pos = ft_make_vector(ft_atof(temp[0]) + cylinder->trans.x,
				ft_atof(temp[1]) + cylinder->trans.y,
				ft_atof(temp[2]) + cylinder->trans.z);
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

t_square	*ft_new_square(t_env *e, char *str)
{
	char		**tab;
	char		**temp;
	t_square	*square;

	tab = NULL;
	temp = NULL;
	square = (t_square *)malloc(sizeof(t_square));
	tab = ft_split(str, ' ');
	temp = ft_split(tab[5], ',');
	square->trans = ft_make_vector(ft_atof(temp[0]),ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[6], ',');
	square->rot = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[1], ',');
	square->pos = ft_make_vector(ft_atof(temp[0]) + square->trans.x,
				ft_atof(temp[1]) + square->trans.y,
				ft_atof(temp[2]) + square->trans.z);
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
	triangle->A = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[2], ',');
	triangle->B = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[3], ',');
	triangle->C = ft_make_vector(ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2]));
	double_free(temp);
	temp = ft_split(tab[4], ',');
	triangle->color = (t_color){ft_atof(temp[0]), ft_atof(temp[1]),
				ft_atof(temp[2])};
	double_free(temp);
	double_free(tab);
	return (triangle);
}