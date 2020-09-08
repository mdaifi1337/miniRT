/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaifi <mdaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:21:36 by mdaifi            #+#    #+#             */
/*   Updated: 2020/03/13 19:51:56 by mdaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <X11/keysymdef.h>
# include "camera.h"
# include "shapes.h"
# include "ft_vectors.h"
# include "../lib/libft.h"
# include "ft_light.h"
# include "my_mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# define min(a,b) (((a) < (b)) ? (a) : (b))
# define max(a,b) (((a) > (b)) ? (a) : (b))
# define PI 3.141592653589793
# define RAY_DIS_MAX 1e30f
# define vibe_check write(1, "v\n", 2);
# define INT_MAX 2147483647
# define KeyPressMask (1L<<0)
# define XK_Escape 0xff1b

typedef struct	s_env
{
	t_mlx			*mlx;
	t_vector		look_at_point;
	t_camera		cam;
	t_camera		*cam_list;
	t_ray			ray;
	t_light			*light_list;
	t_Alight		ambient;
	t_color			diffuse;
	t_color			specular;
	t_color			phong;
	t_scene			*scene_head;
	t_scene			*object;
	t_plane			plane;
	int				x;
	int				y;
	int				WIDTH;
	int				HEIGHT;
	int				resolution;
	double			a;
	double			b;
	double			c;
	double			t1;
	double			t2;
	double			discr;
	double			sqrtdiscr;
	double			distance;
	double			rot_x;
	double			R;
}				t_env;

int			ft_ray_cast(t_env *e, t_scene *head);
int			ft_shadow_cast(t_env *e, t_scene *head);
int			ft_plane_shadow(t_env *e, t_scene *scene);
int			ft_sphere_shadow(t_env *e, t_scene *scene);
int			ft_square_shadow(t_env *e, t_scene *scene);
int			ft_cylinder_shadow(t_env *e, t_scene *scene);
int			ft_triangle_shadow(t_env *e, t_scene *scene);
int			intersectRayPlane(t_env *e, t_plane *plane);
int			intersectRaySphere(t_env *e, t_sphere *sphere);
int			intersectRaySquare(t_env *e, t_square *square);
int			intersectRayCylinder(t_env *e, t_cylinder *cylinder);
int			intersectRayTriangle(t_env *e, t_triangle *triangle);
int			ft_free_error(char **tab);
int     	ft_check_light(char *str);
int			ft_check_camera(t_env *e, char **str);
int			ft_check_plane(char *str);
int			ft_check_sphere(char *str);
int			ft_check_cylinder(char *str);
int			ft_check_triangle(char *str);
int			ft_check_square(char *str);
int			ft_check_ambient(t_env *e, char **str);
int    		ft_check_file(t_env *e, char **tab);
int    		ft_check_tab_int(char **tab, char *str);
int    		ft_check_tab_double(char **tab, char *str);
int			ft_check_resolution(t_env *e, char **str);
int			ft_check_vector(char **tab, char *str);
int			ft_check_color(char **tab, char *str);
int			ft_check_normal(char **tab, char *str);
int			ft_check_int_between(char *tab, char *str, int min, int max);
int			ft_check_between(char *tab, char *str, double min, double max);
int   		ft_check_nbr(char **tab, char *str, int nbr);
int	    	ft_check_tab_between(char **tab, int min, int max, char *str);
double		ft_radians(int fov);
double		getNorm(t_vector res);
double		ft_atof(const char *str);
double		ft_vector_dot(t_vector v1, t_vector v2);
void		init_vars(t_env *e);
void		init_phong(t_env *e);
void		double_free(char **str);
void		normalize(t_vector *ret);
void		ft_parse(char *file, t_env *e);
void		ft_make_ray(t_env *mlx, int x, int y);
void		ft_get_normal(t_env *e, t_scene *head);
void		final_color(t_env *e, t_Alight *ambient);
void		ft_window_resolution(char *str, t_env *e);
void		clamp_colors(t_color *clr, int min, int max);
void		check_plane(t_env *e, t_scene *scene, int *ret);
void		check_sphere(t_env *e, t_scene *scene, int *ret);
void		check_square(t_env *e, t_scene *scene, int *ret);
void		check_cylinder(t_env *e, t_scene *scene, int *ret);
void		check_triangle(t_env *e, t_scene *scene, int *ret);
void		ft_add_plane(t_env *e, char *str);
void		ft_add_sphere(t_env *e, char *str);
void		ft_add_square(t_env *e, char *str);
void		ft_add_cylinder(t_env *e, char *str);
void		ft_add_triangle(t_env *e, char *str);
void		ft_add_cam(t_camera **list, char *str);
void		ft_add_light(t_light **list, char *str);
void		ft_diffuse(t_scene *scene, t_env *mlx, t_light *light);
void		ft_light(t_env *e, t_scene *scene, t_scene *head, t_light *lights);
void		ft_specular(t_scene *scene, t_env *mlx, t_light *light, t_vector tmp);
void		ft_free_strings(char **scene, char *str);
void		init_lists(t_env **e);
void		camera(t_env *e);
t_mlx		*init(t_env *e);
t_light		*ft_new_light(char *str);
t_camera	*ft_new_camera(char *str);
t_Alight	ft_new_ambient(char *str);
t_vector	getNormalized(t_vector res);
t_vector	ft_negate_vector(t_vector v);
t_Alight	ft_ambient(t_scene *scene, t_env *e);
t_vector	vectorScale(double c, t_vector v);
t_vector	ft_vector_add(t_vector v1, t_vector v2);
t_vector	ft_vector_sub(t_vector v1, t_vector v2);
t_vector	cross_product(t_vector *v1, t_vector *v2);
t_vector	ft_make_vector(double x, double y, double z);
t_plane		*ft_new_plane(char *str);
t_sphere	*ft_new_sphere(char *str);
t_square	*ft_new_square(char *str);
t_cylinder	*ft_new_cylinder(char *str);
t_triangle	*ft_new_triangle(char *str);

#endif