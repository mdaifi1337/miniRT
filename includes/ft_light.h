/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:11:54 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/12 16:42:05 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIGHT_H
# define FT_LIGHT_H
# include "ft_vectors.h"

typedef struct	s_light
{
	t_vector		dist_to_light;
	t_vector		pos;
	t_color			color;
	double			intensity;
	struct s_light	*next;
}				t_light;

typedef struct	s_Alight
{
	int			found;
	double		intensity;
	t_color		color;
}				t_Alight;

#endif