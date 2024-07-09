NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = 	./src/main.c ./src/check_player.c ./src/map_control.c ./src/map_info_color.c \
		./src/map_info.c ./src/map_init.c ./src/map_parse.c \
		./src/map_print.c ./src/map_utils.c ./src/map_utils2.c ./src/mlx_utils.c \
		./src/movement.c ./src/raycast_man.c ./src/raycasting.c ./src/real_map.c \
		./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_memset.c \
		./libft/ft_strlen.c ./libft/ft_strtrim.c ./libft/get_next_line.c \
		./libft/is_digit.c ./libft/split.c ./libft/strjoin.c ./libft/strlcpy.c \
		./libft/strncmp.c ./libft/substr.c ./libft/strdup.c ./libft/strchr.c

OBJS = $(SRCS:.c=.o)
RM = rm -f
MLX =./minilibx/libmlx.a
LIBS = -L./minilibx -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(MLX):
	@$(MAKE) -C minilibx

clean:
	@$(MAKE) -C minilibx clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re