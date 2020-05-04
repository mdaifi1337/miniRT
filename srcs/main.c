#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "../includes/MiniRT.h"
#include <mlx.h>
#include <math.h>
#include <fcntl.h>

int	get_int(t_color clr)
{
	char color[4];

	//clamp_colors aka 0 > color > 255
	color[0] = clr.blue * 255; //bleu
	color[1] = clr.green * 255;	//green
	color[2] = clr.red * 255;	//red
	color[3] = 0;
	return (*(int *)color);
}

void	clamp_colors(t_color *clr, int min, int max)
{
	clr->red = clr->red < min ? min : clr->red;
	clr->red = clr->red > max ? max : clr->red;
	clr->green = clr->green < min ? min : clr->green;
	clr->green = clr->green > max ? max : clr->green;
	clr->blue = clr->blue < min ? min : clr->blue;
	clr->blue = clr->blue > max ? max : clr->blue;
}

void	draw(t_env *e, t_scene *head)
{
	e->x = 0;
	camera(e);
	while (e->x < e->WIDTH)
	{
		e->y = e->HEIGHT;
		while (e->y > 0)
		{
			ft_make_ray(e, e->x, e->y);
			if (ft_ray_cast(e, head))
			{
				ft_light(e, e->object, head, e->light_list);
				e->mlx->mlx_data[(e->HEIGHT - e->y)
				* e->WIDTH + e->x] = get_int(e->phong);
			}
			e->y--;
		}
		e->x++;
	}
}

int key(int khook, t_env *e)
{	
	if (khook == 53)
		exit(0);
	if (khook == 88)
	{
		if (e->rot_x == 360)
			e->rot_x = 0;
		e->cam.pos.x += e->R * cos(e->rot_x);
		// e->cam.pos.z += e->R * sin(e->rot_x);
		e->rot_x++;
		printf("%f\n", e->rot_x);
		mlx_clear_window(e->mlx->mlx_ptr, e->mlx->mlx_win);
		mlx_destroy_image(e->mlx->mlx_ptr, e->mlx->mlx_img);
		e->mlx->mlx_img = mlx_new_image(e->mlx->mlx_ptr, e->WIDTH, e->HEIGHT);
		e->mlx->mlx_data = (int *)mlx_get_data_addr(e->mlx->mlx_img, &e->mlx->bpp, &e->mlx->size_l, &e->mlx->endian);
		draw(e, e->scene_head);
		mlx_put_image_to_window(e->mlx->mlx_ptr, e->mlx->mlx_win, e->mlx->mlx_img, 0, 0);
	}
	// if (khook == 84)
	// {
	// 	e->cam.pos.z += 0.01;
	// 	mlx_clear_window(e->mlx->mlx_ptr, e->mlx->mlx_win);
	// 	mlx_destroy_image(e->mlx->mlx_ptr, e->mlx->mlx_img);
	// 	e->mlx->mlx_img = mlx_new_image(e->mlx->mlx_ptr, e->WIDTH, e->HEIGHT);
	// 	e->mlx->mlx_data = (int *)mlx_get_data_addr(e->mlx->mlx_img, &e->mlx->bpp, &e->mlx->size_l, &e->mlx->endian);
	// 	draw(e);
	// 	mlx_put_image_to_window(e->mlx->mlx_ptr, e->mlx->mlx_win, e->mlx->mlx_img, 0, 0);
	// }
	// if (khook == 91)
	// {
	// 	e->cam.pos.z -= 0.01;
	// 	mlx_clear_window(e->mlx->mlx_ptr, e->mlx->mlx_win);
	// 	mlx_destroy_image(e->mlx->mlx_ptr, e->mlx->mlx_img);
	// 	e->mlx->mlx_img = mlx_new_image(e->mlx->mlx_ptr, e->WIDTH, e->HEIGHT);
	// 	e->mlx->mlx_data = (int *)mlx_get_data_addr(e->mlx->mlx_img, &e->mlx->bpp, &e->mlx->size_l, &e->mlx->endian);
	// 	draw(e);
	// 	mlx_put_image_to_window(e->mlx->mlx_ptr, e->mlx->mlx_win, e->mlx->mlx_img, 0, 0);
	// }
	// if (khook == 124)
	// {
	// 	e->cam.pos.x -= 0.01;
	// 	mlx_clear_window(e->mlx->mlx_ptr, e->mlx->mlx_win);
	// 	mlx_destroy_image(e->mlx->mlx_ptr, e->mlx->mlx_img);
	// 	e->mlx->mlx_img = mlx_new_image(e->mlx->mlx_ptr, e->WIDTH, e->HEIGHT);
	// 	e->mlx->mlx_data = (int *)mlx_get_data_addr(e->mlx->mlx_img, &e->mlx->bpp, &e->mlx->size_l, &e->mlx->endian);
	// 	draw(e);
	// 	mlx_put_image_to_window(e->mlx->mlx_ptr, e->mlx->mlx_win, e->mlx->mlx_img, 0, 0);
	// }
	// if (khook == 123)
	// {
	// 	e->cam.pos.x += 0.01;
	// 	mlx_clear_window(e->mlx->mlx_ptr, e->mlx->mlx_win);
	// 	mlx_destroy_image(e->mlx->mlx_ptr, e->mlx->mlx_img);
	// 	e->mlx->mlx_img = mlx_new_image(e->mlx->mlx_ptr, e->WIDTH, e->HEIGHT);
	// 	e->mlx->mlx_data = (int *)mlx_get_data_addr(e->mlx->mlx_img, &e->mlx->bpp, &e->mlx->size_l, &e->mlx->endian);
	// 	draw(e);
	// 	mlx_put_image_to_window(e->mlx->mlx_ptr, e->mlx->mlx_win, e->mlx->mlx_img, 0, 0);
	// }
	// if (khook == 125)
	// {
	// 	e->cam.pos.y -= 0.01;
	// 	mlx_clear_window(e->mlx->mlx_ptr, e->mlx->mlx_win);
	// 	mlx_destroy_image(e->mlx->mlx_ptr, e->mlx->mlx_img);
	// 	e->mlx->mlx_img = mlx_new_image(e->mlx->mlx_ptr, e->WIDTH, e->HEIGHT);
	// 	e->mlx->mlx_data = (int *)mlx_get_data_addr(e->mlx->mlx_img, &e->mlx->bpp, &e->mlx->size_l, &e->mlx->endian);
	// 	draw(e);
	// 	mlx_put_image_to_window(e->mlx->mlx_ptr, e->mlx->mlx_win, e->mlx->mlx_img, 0, 0);
	// }
	// if (khook == 126)
	// {
	// 	e->cam.pos.y += 0.01;
	// 	mlx_clear_window(e->mlx->mlx_ptr, e->mlx->mlx_win);
	// 	mlx_destroy_image(e->mlx->mlx_ptr, e->mlx->mlx_img);
	// 	e->mlx->mlx_img = mlx_new_image(e->mlx->mlx_ptr, e->WIDTH, e->HEIGHT);
	// 	e->mlx->mlx_data = (int *)mlx_get_data_addr(e->mlx->mlx_img, &e->mlx->bpp, &e->mlx->size_l, &e->mlx->endian);
	// 	draw(e);
	// 	mlx_put_image_to_window(e->mlx->mlx_ptr, e->mlx->mlx_win, e->mlx->mlx_img, 0, 0);
	// }
	return (0);
}

int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		printf("%d, %d\n", x, y);
		return (1);
	}
	return (0);
}

int main()
{
	t_env e;

	init_vars(&e);
	ft_parse("test.rt", &e);
	e.mlx = init(&e);
	e.rot_x = 0;
	// // e->cam.pos = (t_vector){0, 0, 0};
	// // e->sphere.pos = (t_vector){0, 0, 30};
	// // e->sphere.color.red = 255;
	// // e->sphere.color.green = 0;
	// // e->sphere.color.blue = 0;
	// // e->sphere.radius = 10;
	// // e->plane.pos = (t_vector){0, -10, 0};
	// // e->plane.normal = (t_vector){0, 1, 0};
	// // e->plane.color = (t_color){0, 255, 255};
	// // e->light.color.red = 255;
	// // e->light.color.green = 255;
	// // e->light.color.blue = 255;
	// // e->light.pos = (t_vector){50, 100, -30};
	// // e->light.intensity = 0.7;
	// // e->ambient.color.red = 255;
	// // e->ambient.color.green = 255;
	// // e->ambient.color.blue = 255;
	// // e->ambient.intensity = 0.2;
	// // e->cam.fov = (90 * PI) / 180;
	e.cam.default_up = (t_vector){0, 1, 0};
	e.R = getNorm(ft_vector_sub(e.cam.pos, e.look_at_point));
	// // printf("%d | %d\n", e->mlx->x, e->mlx->y);
	draw(&e, e.scene_head);
	mlx_hook(e.mlx->mlx_win, 17, 0, &close_win, &e);
	mlx_hook(e.mlx->mlx_win, 2, 0, key, &e);
	mlx_hook(e.mlx->mlx_win, 4, 0, mouse_press, &e);
	mlx_put_image_to_window(e.mlx->mlx_ptr, e.mlx->mlx_win, e.mlx->mlx_img, 0, 0);
	mlx_loop(e.mlx->mlx_ptr);
	return (0);
}