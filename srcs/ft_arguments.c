/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:23:18 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/28 18:03:58 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	ft_check_file_ext(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
	{
		write(1, "Error\nPlease enter config file !..\n", 36);
		exit(1);
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 't' || argv[1][i - 2] != 'r'
		|| argv[1][i - 3] != '.' || (i - 3 == 0))
	{
		write(1, "Error\nfile entered is not a .rt file !..\n", 42);
		exit(1);
	}
}

void	ft_check_second_arg(t_env *e, int argc, char *str)
{
	if (argc == 3)
	{
		if (ft_strncmp(str, "--save", 7) == 0)
			e->save = 1;
		else
		{
			write(1, "Error\nInvalid second argument !..\n", 35);
			exit(1);
		}
	}
}
