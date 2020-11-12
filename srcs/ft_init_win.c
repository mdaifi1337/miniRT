/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:55:40 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/08 19:21:34 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

t_mlx		*init(t_env *e)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, e->width, e->height, "MiniRT");
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, e->width, e->height);
	mlx->mlx_data = (int *)mlx_get_data_addr(mlx->mlx_img, &mlx->bpp,
					&mlx->size_l, &mlx->endian);
	return (mlx);
}

void		ft_window_resolution(char *str, t_env *e)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(str, ' ');
	if ((e->width = ft_atof(tab[1])) > 2560)
		e->width = 2560;
	if ((e->height = ft_atof(tab[2])) > 1440)
		e->height = 1440;
	double_free(tab);
}

static int	ft_check_int_positive(char *tab, char *str)
{
	char	**tmp;

	tmp = ft_split(tab, ' ');
	if (!ft_check_nbr(tab, str, 3, ' ') || !ft_is_int(tmp[1], str) ||
		!ft_is_int(tmp[2], str))
		return (0);
	if (ft_atof(tmp[1]) < 0 || ft_atof(tmp[2]) < 0)
	{
		write(1, str, ft_strlen(str));
		return (0);
	}
	return (1);
}

static int	ft_res_not_found(t_env *e)
{
	if (e->resolution == 0)
	{
		write(1, "Error, Resolution not found !..\n", 33);
		return (0);
	}
	return (1);
}

int			ft_check_resolution(t_env *e, char **str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == 'R' && str[i][1] == ' ')
		{
			e->resolution += 1;
			if (e->resolution > 1)
			{
				write(1, "Duplicate resolution !..\n", 26);
				return (0);
			}
			if (!ft_check_int_positive(str[i],
				"Invalid Resolution value(s)..\n"))
				return (0);
		}
	}
	if (!ft_res_not_found(e))
		return (0);
	return (1);
}
