/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:42:21 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/06 18:58:18 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_sphere	*ft_new_sphere(char *str)
{
	char		**tab;
	char		**tmp;
	t_sphere	*sp;

	tab = NULL;
	tmp = NULL;
	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	tab = ft_split(str, ' ');
	tmp = ft_split(tab[4], ',');
	sp->trs = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	tmp = ft_split(tab[1], ',');
	sp->pos = ft_make_vector(ft_atof(tmp[0]) + sp->trs.x,
			ft_atof(tmp[1]) + sp->trs.y, ft_atof(tmp[2]) + sp->trs.z);
	sp->radius = ft_atof(tab[2]);
	double_free(tmp);
	tmp = ft_split(tab[3], ',');
	sp->color = (t_color){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	double_free(tab);
	return (sp);
}

t_plane		*ft_new_plane(char *str)
{
	char		**tab;
	char		**tmp;
	t_plane		*pl;

	tab = NULL;
	tmp = NULL;
	if (!(pl = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	tab = ft_split(str, ' ');
	pl->trs = ft_add_trs(tab[4]);
	pl->rot = ft_add_rot(tab[5]);
	tmp = ft_split(tab[1], ',');
	pl->pos = (t_vector){ft_atof(tmp[0]) + pl->trs.x,
				ft_atof(tmp[1]) + pl->trs.y, ft_atof(tmp[2]) + pl->trs.z};
	double_free(tmp);
	tmp = ft_split(tab[2], ',');
	pl->normal = (t_vector){ft_atof(tmp[0]) + pl->rot.x, ft_atof(tmp[1])
				+ pl->rot.y, ft_atof(tmp[2]) + pl->rot.z};
	double_free(tmp);
	tmp = ft_split(tab[3], ',');
	pl->color = (t_color){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	double_free(tab);
	return (pl);
}

t_cylinder	*ft_new_cylinder(char *str)
{
	char		**tab;
	char		**tmp;
	t_cylinder	*cy;

	tab = NULL;
	tmp = NULL;
	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	tab = ft_split(str, ' ');
	ft_add_trs_and_rot(&cy->trs, tab[6], &cy->rot, tab[7]);
	tmp = ft_split(tab[1], ',');
	cy->pos = (t_vector){ft_atof(tmp[0]) + cy->trs.x,
				ft_atof(tmp[1]) + cy->trs.y, ft_atof(tmp[2]) + cy->trs.z};
	double_free(tmp);
	tmp = ft_split(tab[2], ',');
	cy->normal = (t_vector){ft_atof(tmp[0]) + cy->rot.x, ft_atof(tmp[1])
				+ cy->rot.y, ft_atof(tmp[2]) + cy->rot.z};
	double_free(tmp);
	cy->width = ft_atof(tab[3]);
	cy->height = ft_atof(tab[4]);
	tmp = ft_split(tab[5], ',');
	cy->color = (t_color){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	double_free(tab);
	return (cy);
}

t_square	*ft_new_square(char *str)
{
	char		**tab;
	char		**tmp;
	t_square	*sq;

	tab = NULL;
	tmp = NULL;
	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	tab = ft_split(str, ' ');
	sq->trs = ft_add_trs(tab[5]);
	sq->rot = ft_add_rot(tab[6]);
	tmp = ft_split(tab[1], ',');
	sq->pos = (t_vector){ft_atof(tmp[0]) + sq->trs.x,
				ft_atof(tmp[1]) + sq->trs.y, ft_atof(tmp[2]) + sq->trs.z};
	double_free(tmp);
	tmp = ft_split(tab[2], ',');
	sq->normal = (t_vector){ft_atof(tmp[0]) + sq->rot.x, ft_atof(tmp[1])
				+ sq->rot.y, ft_atof(tmp[2]) + sq->rot.z};
	double_free(tmp);
	sq->side = ft_atof(tab[3]);
	tmp = ft_split(tab[4], ',');
	sq->color = (t_color){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	double_free(tab);
	return (sq);
}

t_triangle	*ft_new_triangle(char *str)
{
	char		**tab;
	char		**tmp;
	t_triangle	*tr;

	tab = NULL;
	tmp = NULL;
	if (!(tr = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	tab = ft_split(str, ' ');
	tmp = ft_split(tab[1], ',');
	tr->a = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	tmp = ft_split(tab[2], ',');
	tr->b = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	tmp = ft_split(tab[3], ',');
	tr->c = (t_vector){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	tmp = ft_split(tab[4], ',');
	tr->color = (t_color){ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])};
	double_free(tmp);
	double_free(tab);
	return (tr);
}
