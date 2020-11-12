/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:21:36 by mdaifi            #+#    #+#             */
/*   Updated: 2020/11/11 19:31:27 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include "ft_camera.h"
# include "ft_shapes.h"
# include "ft_vectors.h"
# include "../lib/libft.h"
# include "ft_light.h"
# include "ft_bitmap.h"
# include "ft_my_mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# define PI 3.141592653589793
# define RAY_DIS_MAX 1e30f
# define INT_MAX 2147483647

typedef struct	s_env
{
	t_mlx		*mlx;
	t_bmp_vars	bmp;
	t_camera	curr_cam;
	t_camera	*it_cam;
	t_camera	*cam_list;
	t_ray		ray;
	t_light		*light_list;
	t_alight	ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		phong;
	t_scene		*scene_head;
	t_scene		*object;
	int			save;
	int			x;
	int			cam_count;
	int			y;
	int			width;
	int			height;
	int			resolution;
	double		a;
	double		b;
	double		c;
	double		t1;
	double		t2;
	double		discr;
	double		sqrtdiscr;
	double		distance;
}				t_env;

int				get_int(t_color clr);
int				ft_ray_cast(t_env *e, t_scene *head);
int				ft_shadow_cast(t_env *e, t_scene *head);
int				ft_plane_shadow(t_env *e, t_scene *scene);
int				ft_sphere_shadow(t_env *e, t_scene *scene);
int				ft_square_shadow(t_env *e, t_scene *scene);
int				ft_cylinder_shadow(t_env *e, t_scene *scene);
int				ft_triangle_shadow(t_env *e, t_scene *scene);
int				key(int khook, t_env *e);
int				close_win(t_env *e);
int				mouse_press(int button, int x, int y, t_env *e);
int				inter_ray_pl(t_env *e, t_plane *plane);
int				inter_ray_sp(t_env *e, t_sphere *sphere);
int				inter_ray_sq(t_env *e, t_square *square);
int				inter_ray_cy(t_env *e, t_cylinder *cylinder);
int				inter_ray_tr(t_env *e, t_triangle *triangle);
int				ft_free_error(char **tab);
int				ft_check_light(char *str);
int				ft_check_trans(char *str, char *ch);
int				ft_check_rot(char *str, char *ch);
int				ft_check_cam(t_env *e, char **str);
int				ft_check_plane(char *str);
int				ft_check_sphere(char *str);
int				ft_check_cylinder(char *str);
int				ft_check_triangle(char *str);
int				ft_check_square(char *str);
int				ft_smallest_value(t_env *e);
int				ft_check_ambient(t_env *e, char **str);
int				ft_check_file(t_env *e, char **tab);
int				ft_check_tab_int(char *tab, char *str);
int				ft_check_tab_double(char *tab, char *str);
int				ft_check_resolution(t_env *e, char **str);
int				ft_check_vector(char *tab, char *str, char c);
int				ft_check_color(char *tab, char *str);
int				ft_check_normal(char *tab, char *str);
int				ft_check_int_between(char *tab, char *str, int min, int max);
int				ft_between(char *tab, char *str, double min, double max);
int				ft_check_nbr(char *tab, char *str, int nbr, char c);
int				ft_check_tab_between(char *tab, int min, int max, char *str);
int				ft_translate(t_env *e, char *str, char **tab, int *i);
double			ft_rad(int angle);
double			get_norm(t_vector res);
double			ft_atof(const char *str);
double			ft_vector_dot(t_vector v1, t_vector v2);
void			camera(t_env *e);
void			init_vars(t_env *e);
void			init_phong(t_env *e);
void			init_lists(t_env **e);
void			double_free(char **str);
void			normalize(t_vector *ret);
void			ft_parse(char *file, t_env *e);
void			ft_draw(t_env *e);
void			plane_normal(t_env *e, t_scene *scene);
void			sphere_normal(t_scene *scene);
void			square_normal(t_env *e, t_scene *scene);
void			triangle_normal(t_scene *scene);
void			cylinder_normal(t_env *e, t_scene *scene);
void			ft_make_ray(t_env *mlx, int x, int y);
void			ft_get_normal(t_env *e, t_scene *head);
void			final_color(t_env *e, t_alight *ambient);
void			ft_free_strings(char **scene, char *str);
void			ft_window_resolution(char *str, t_env *e);
void			ft_store_bmp_data(t_env *e);
void			ft_check_file_ext(int argc, char **argv);
void			ft_check_second_arg(t_env *e, int argc, char *str);
void			clamp_colors(t_color *clr, int min, int max);
void			check_plane(t_env *e, t_scene *scene, int *ret);
void			check_sphere(t_env *e, t_scene *scene, int *ret);
void			check_square(t_env *e, t_scene *scene, int *ret);
void			check_cylinder(t_env *e, t_scene *scene, int *ret);
void			check_triangle(t_env *e, t_scene *scene, int *ret);
void			ft_add_cam(t_env *e, char *str);
void			ft_add_plane(t_env *e, char *str);
void			ft_add_sphere(t_env *e, char *str);
void			ft_add_square(t_env *e, char *str);
void			ft_add_cylinder(t_env *e, char *str);
void			ft_add_triangle(t_env *e, char *str);
void			ft_add_light(t_light **list, char *str);
void			ft_save_bmp(t_env *e);
void			ft_diffuse(t_scene *scene, t_env *mlx, t_light *light);
void			ft_light(t_env *e, t_scene *scene, t_scene *head,
						t_light *lights);
void			ft_specular(t_scene *scene, t_env *mlx, t_light *light,
							t_vector tmp);
void			ft_add_trs_and_rot(t_vector *trs, char *str1,
				t_vector *rot, char *str2);
unsigned char	*ft_bmp_header(t_bfh bfh, t_bih bih);
t_mlx			*init(t_env *e);
t_vector		ft_add_trs(char *str);
t_vector		ft_add_rot(char *str);
t_bih			ft_init_bmp_info_header(t_env *e);
t_bfh			ft_init_bmp_header(t_bih bih);
t_vector		get_normalized(t_vector res);
t_alight		ft_ambient(t_scene *scene, t_env *e);
t_vector		vector_scale(double c, t_vector v);
t_vector		ft_vector_add(t_vector v1, t_vector v2);
t_vector		ft_vector_sub(t_vector v1, t_vector v2);
t_vector		cross_product(t_vector *v1, t_vector *v2);
t_vector		ft_make_vector(double x, double y, double z);
t_vector		ft_rot(t_vector v, double alpha, double beta, double gamma);
t_light			*ft_new_light(char *str);
t_camera		*ft_new_camera(char *str);
t_alight		ft_new_ambient(char *str);
t_plane			*ft_new_plane(char *str);
t_sphere		*ft_new_sphere(char *str);
t_square		*ft_new_square(char *str);
t_cylinder		*ft_new_cylinder(char *str);
t_triangle		*ft_new_triangle(char *str);

#endif
