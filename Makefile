NAME = cub3D
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = libft/libft.a
LIBFT_PATH = ./libft

SRC = main.c exit/exit1.c game_funcs/gameloop.c game_funcs/playermv.c\
			game_funcs/turn.c get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c map/map1.c map/map2.c\
			map/map_checker.c map/initialization.c map/setcolortexture.c\
			raycast/raycast.c raycast/calculations.c raycast/calculations1.c

OBJ = $(SRC:.c=.o)

MINILIBX_PATH = ./minilibx
MINILIBX = $(MINILIBX_PATH)/libmlx.a
MINILIBX_FLAGS = -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJ)	
	@$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJ) $(MINILIBX) $(MINILIBX_FLAGS)

$(MINILIBX):
	@make -C $(MINILIBX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make clean -C $(MINILIBX_PATH)
	@make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

norminette :
	@find . -type f \( -name "*.c" -o -name "*.h" \) ! -path "$(MINILIBX_PATH)/*" -exec norminette {} +

.PHONY: all clean fclean re
