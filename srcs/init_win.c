/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:55:40 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 17:48:20 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

t_mlx	*init(t_env *e)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, e->WIDTH, e->HEIGHT, "MiniRT");
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, e->WIDTH, e->HEIGHT);
	mlx->mlx_data = (int *)mlx_get_data_addr(mlx->mlx_img, &mlx->bpp, &mlx->size_l, &mlx->endian);
	return (mlx);
}

void	ft_window_resolution(char *str, t_env *e)
{
	char	**tab;
	
	tab = NULL;
	tab = ft_split(str, ' ');
	if ((e->WIDTH = ft_atof(tab[1])) > 2560)
		e->WIDTH = 2560;
	if ((e->HEIGHT = ft_atof(tab[2])) > 1440)
		e->HEIGHT = 1440;
	double_free(tab);
}

static int	ft_check_int_positive(char **tab, char *str)
{
	if (ft_check_nbr(tab, str, 3) == -1 ||
		ft_is_int(tab[1], str) == -1 ||
		ft_is_int(tab[2], str) == -1)
		return (-1);
	if (ft_atof(tab[1]) < 0 || ft_atof(tab[2]) < 0)
	{
		write(1, str, ft_strlen(str));
		return (-1);
	}
	return (1);
}

int	ft_check_resolution(t_env *e, char **str)
{
	char	**tab;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == 'R')
		{
			e->resolution++;
			if (e->resolution > 1)
			{
				write(1, "Error, Duplicate resolution !..\n", 33);
				return (-1);
			}
			tab = ft_split(str[i], ' ');
			if (ft_check_int_positive(tab, "Error, Invalid Resolution..\n") == -1)
				return (ft_free_error(tab));
			double_free(tab);
		}
	}
	if (e->resolution == 0)
	{
		write(1, "Error, Resolution not found !..\n", 33);
		return (-1);
	}
	return (1);
}