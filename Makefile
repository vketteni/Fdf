CC= cc
CFLAGS= -Wall -Wextra -Werror -g
INC= -Iget_next_line -Ilibft -I$(MLX)include -I.
NAME= fdf
MAKEFLAGS= --no-print-directory
MLX42_A= MLX42/libmlx42.a
SCRS= source/fdf.c \
	source/parse.c \
	source/checker.c \
	source/coordinate.c \
	source/isometric.c \
	source/free.c \
	source/hooks.c \
	source/initialize.c \
	source/bresenham.c \
	source/utils/utils1.c \
	source/utils/utils2.c \
	source/utils/utils3.c \
	source/utils/utils4.c \
	source/utils/draw_utils1.c \

OBJS= $(SCRS:.c=.o)

all: build-MLX42 $(NAME)

$(NAME): $(OBJS)
	@printf "\033[0;32mCompiling: LIBFT\n\033[0m"
	@make -C libft
	@printf "\033[0;32mCompiling: GNL\n\033[0m"
	@make -C get_next_line
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) MLX42/libmlx42.a libft/libft.a get_next_line/get_next_line.a -lm -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.9/lib/"

build-MLX42:
	@if [ ! -f "$(MLX42_A)" ]; then \
		git submodule update --init --recursive; \
		echo $(MLX42_A); \
		echo "$(MLX42_A) file not found, running CMake..."; \
		cd MLX42 && cmake . && make; \
	fi

clean:
	make -C get_next_line clean
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	${MAKE} -C get_next_line fclean
	${MAKE} -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
