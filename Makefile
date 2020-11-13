NAME = miniRT
FLAGS = -Wall -Werror -Wextra
LIBS= -g -lm -lmlx -framework OpenGl -framework AppKit
SRCS = srcs/main.c srcs/ft_vector_operations.c srcs/ft_vectors.c \
	   srcs/ft_lights.c srcs/ft_shapes_inter.c srcs/ft_new_objects.c \
	   srcs/ft_add_objects.c srcs/ft_tools.c srcs/ft_parser.c srcs/ft_init_win.c \
	   srcs/ft_color.c srcs/ft_init_vars.c srcs/ft_casting.c \
	   srcs/ft_check_intersection.c srcs/ft_normals.c srcs/ft_check_file.c \
	   srcs/ft_objects_shadow.c srcs/ft_check_values.c srcs/ft_check_lights.c \
	   srcs/ft_check_objects.c srcs/ft_check_functions.c srcs/ft_camera.c \
	   srcs/ft_translate.c srcs/ft_rotations.c srcs/ft_ray.c \
	   srcs/ft_get_normal.c srcs/ft_shapes_inter2.c srcs/ft_key_hooks.c \
	   srcs/ft_bmp_functions.c srcs/ft_init_bmp.c srcs/ft_draw_image.c \
	   srcs/ft_tools2.c srcs/ft_arguments.c
OBJ = $(SRCS:.c=.o)
LIBFT = lib/libft.a
all: $(NAME)


lib_rule:
	make -C ./lib

$(NAME): lib_rule $(OBJ)
		gcc $(LIBFT) $(OBJ) $(FLAGS) -o $(NAME) $(LIBS) 

%.o: %.c
		gcc $(FLAGS) -g -c $< -o $@

clean:
		make clean -C ./lib
		rm miniRT.bmp
		rm -f srcs/*.o
fclean: clean
		make fclean -C ./lib
		rm -f $(NAME)
re: fclean all