/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:21:31 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/13 19:51:52 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniRT.h"

char	*read_file(char *file)
{
	int		fd;
	int		ret;
	char	*ch;
	char	buff[101];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if ((ret = read(fd, buff, 0)) < 0)
		exit(0);
	ch = ft_strdup("");
	while ((ret = read(fd, buff, 100)) > 0)
	{
		buff[ret] = '\0';
		ch = ft_strjoin(ch, buff);
	}
	close(fd);
	return (ch);
}

void	ft_parse(char *file, t_env *e)
{
	char			*str;
	char			**tab;
	int				i;
	t_light			*light;

	str = NULL;
	tab = NULL;
	i = 0;
	str = read_file(file);
	tab = ft_split(str, '\n');
	if (ft_check_file(e, tab) == -1)
	{
		double_free(tab);
		free(str);
		exit(1);
	}
	init_lists(&e);
	while (tab[i])
	{
		if (tab[i][0] == 'R')
			ft_window_resolution(tab[i], e);
		if (tab[i][0] == 'A')
			e->ambient = ft_new_ambient(tab[i]);
		if (tab[i][0] == 'c' && tab[i][1] == ' ')
			e->cam = ft_new_camera(tab[i]);
		if (tab[i][0] == 'l')
			ft_add_light(&e->light_list, tab[i]);
		if (tab[i][0] == 'p' && tab[i][1] == 'l')
			ft_add_plane(e, tab[i]);
		if (tab[i][0] == 's' && tab[i][1] == 'p')
			ft_add_sphere(e, tab[i]);
		if (tab[i][0] == 's' && tab[i][1] == 'q')
			ft_add_square(e, tab[i]);
		if (tab[i][0] == 'c' && tab[i][1] == 'y')
			ft_add_cylinder(e, tab[i]);
		if (tab[i][0] == 't' && tab[i][1] == 'r')
			ft_add_triangle(e, tab[i]);
		i++;
	}
	ft_free_strings(tab, str);
}

void	init_lists(t_env **e)
{
	(*e)->light_list = NULL;
	(*e)->scene_head = NULL;
}

void	ft_free_strings(char **scene, char *str)
{
	free(str);
	double_free(scene);
}