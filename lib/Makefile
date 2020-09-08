NAME= libft.a
SRCS= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isalpha.c ft_calloc.c ft_isprint.c \
		ft_isdigit.c ft_memchr.c ft_memcmp.c ft_memccpy.c ft_memset.c ft_memmove.c ft_memcpy.c \
		ft_itoa.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_strchr.c ft_strdup.c ft_strlcpy.c ft_strlcat.c ft_strjoin.c ft_strmapi.c ft_strrchr.c \
		ft_strnstr.c ft_split.c ft_toupper.c ft_strncmp.c ft_tolower.c ft_substr.c ft_strtrim.c \
		ft_bzero.c ft_memmove.c ft_strjoin.c ft_count_table.c ft_is_int.c ft_is_double.c \
		ft_is_between.c ft_check_commas.c
BONUSES= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ=$(SRCS:.c=.o)
BOBJ=$(BONUSES:.c=.o)
FLG= -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
%.o : %.c
	gcc $(FLG) $<

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

bonus:
	gcc $(FLG) $(BONUSES)
	ar rc $(NAME) $(BOBJ)
	ranlib $(NAME)
