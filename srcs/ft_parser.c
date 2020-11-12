/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:21:31 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/08 18:47:47 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

char		*read_file(char *file)
{
	int		fd;
	int		ret;
	char	*ch;
	char	buff[101];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ch = strerror(errno);
		write(1, ch, ft_strlen(ch));
		write(1, "\n", 1);
		exit(1);
	}
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

static void	ft_parse_file(t_env *e, char **tab, int i)
{
	int	j;

	j = 0;
	while (tab[i][j] == ' ')
		j++;
	if (tab[i][j] == 'R' && tab[i][j + 1] == ' ')
		ft_window_resolution(tab[i], e);
	if (tab[i][j] == 'A' && tab[i][j + 1] == ' ')
		e->ambient = ft_new_ambient(tab[i]);
	if (tab[i][j] == 'c' && tab[i][j + 1] == ' ')
		ft_add_cam(e, tab[i]);
	if (tab[i][j] == 'l' && tab[i][j + 1] == ' ')
		ft_add_light(&e->light_list, tab[i]);
	if (tab[i][j] == 'p' && tab[i][j + 1] == 'l')
		ft_add_plane(e, tab[i]);
	if (tab[i][j] == 's' && tab[i][j + 1] == 'p')
		ft_add_sphere(e, tab[i]);
	if (tab[i][j] == 's' && tab[i][j + 1] == 'q')
		ft_add_square(e, tab[i]);
	if (tab[i][j] == 'c' && tab[i][j + 1] == 'y')
		ft_add_cylinder(e, tab[i]);
	if (tab[i][j] == 't' && tab[i][j + 1] == 'r')
		ft_add_triangle(e, tab[i]);
}

void		ft_parse(char *file, t_env *e)
{
	char		*str;
	char		**tab;
	int			i;

	str = NULL;
	tab = NULL;
	str = read_file(file);
	tab = ft_split(str, '\n');
	if (!ft_check_file(e, tab))
	{
		ft_free_strings(tab, str);
		exit(1);
	}
	init_lists(&e);
	i = 0;
	while (tab[i])
	{
		ft_parse_file(e, tab, i);
		i++;
	}
	ft_free_strings(tab, str);
}

void		init_lists(t_env **e)
{
	(*e)->light_list = NULL;
	(*e)->scene_head = NULL;
	(*e)->cam_list = NULL;
}

void		ft_free_strings(char **scene, char *str)
{
	free(str);
	double_free(scene);
}
