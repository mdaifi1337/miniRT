/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:21:31 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/28 17:31:29 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

static void	ft_file_error(int fd)
{
	char	*ch;

	if (fd < 0)
	{
		ch = strerror(errno);
		write(1, ch, ft_strlen(ch));
		free(ch);
		write(1, "\n", 1);
		exit(1);
	}
}

static char	*read_file(char *file)
{
	int		fd;
	int		ret;
	char	*ch;
	char	*tmp;
	char	buff[101];

	fd = open(file, O_RDONLY);
	ft_file_error(fd);
	if ((ret = read(fd, buff, 0)) < 0)
		exit(1);
	ch = ft_strdup("");
	while ((ret = read(fd, buff, 100)) > 0)
	{
		buff[ret] = '\0';
		tmp = ch;
		ch = ft_strjoin(ch, buff);
		free(tmp);
	}
	close(fd);
	return (ch);
}

static void	ft_misconfigured(char **str, int i)
{
	if (i - 1 < 0)
		write(1, "Error\nMisconfiguration at the first line !..\n", 46);
	else
	{
		write(1, "Error\nMisconfiguration after : ", 31);
		write(1, str[i - 1], ft_strlen(str[i - 1]));
		write(1, "\n", 1);
	}
	exit(1);
}

static void	ft_parse_file(t_env *e, char **tab, int *i)
{
	int	j;

	j = 0;
	while (tab[*i][j] == ' ')
		j++;
	if (!ft_strncmp(tab[*i], "R ", 2))
		ft_window_resolution(tab[*i], e);
	else if (!ft_strncmp(tab[*i], "A ", 2))
		e->ambient = ft_new_ambient(tab[*i]);
	else if (!ft_strncmp(tab[*i], "c ", 2))
		ft_add_cam(e, tab, i);
	else if (!ft_strncmp(tab[*i], "l ", 2))
		ft_add_light(&e->light_list, tab, i);
	else if (!ft_strncmp(tab[*i], "pl ", 3))
		ft_add_plane(e, tab, i);
	else if (!ft_strncmp(tab[*i], "sp ", 3))
		ft_add_sphere(e, tab, i);
	else if (!ft_strncmp(tab[*i], "sq ", 3))
		ft_add_square(e, tab, i);
	else if (!ft_strncmp(tab[*i], "cy ", 3))
		ft_add_cylinder(e, tab, i);
	else if (!ft_strncmp(tab[*i], "tr ", 3))
		ft_add_triangle(e, tab, i);
	else
		ft_misconfigured(tab, *i);
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
		ft_parse_file(e, tab, &i);
		i++;
	}
	ft_free_strings(tab, str);
}
