NAME=fdf
GNL=get_next_line/
LIBFT=libft/
MLX42=MLX42/
GNL_A=get_next_line/get_next_line.a
LIBFT_A=libft/libft.a
MLX42_A=MLX42/libmlx42.a
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
RM=rm -f
INC= -I$(GNL) -I$(LIBFT) -I$(MLX)include -I.
SCRS= source/fdf.c \
	source/parse.c \
	source/free.c \
	source/hooks.c \
	source/initialize.c \
	source/utils/utils1.c \
	
OBJS=$(SCRS:.c=.o)

all: build-MLX42 $(NAME) 

$(NAME): $(OBJS) $(GNL_A) $(LIBFT_A) $(MLX42_A) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_A) $(LIBFT_A) $(MLX42_A) -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.9/lib/"

init-submodule:
	git submodule update --init --recursive

build-MLX42: init-submodule
	@if [ ! -f "$(MLX42_A)" ]; then \
		echo $(MLX42_A); \
		echo "$(MLX42_A) file not found, running CMake..."; \
		cd $(MLX42) && cmake . && make; \
	else \
    	echo "$(MLX42_A) file exists, skipping CMake..."; \
	fi

$(GNL_A):
	$(MAKE) -C $(GNL)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(MLX42_A):
	$(MAKE) -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	${MAKE} -C $(GNL) clean
	${MAKE} -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	${MAKE} -C $(GNL) fclean
	${MAKE} -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
