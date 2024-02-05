NAME=fdf
GNL=get_next_line/
LIBFT=libft/
MLX=MLX42/
GNL_A=$(GNL)get_next_line.a
LIBFT_A=$(LIBFT)libft.a
MLX_A=$(MLX)build/libmlx42.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
AR=ar rcs
INC= -I$(GNL) -I$(LIBFT) -I$(MLX)include -I.
SCRS=fdf.c 
OBJS=$(SCRS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNL_A) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_A) $(LIBFT_A) $(MLX_A) -lXext -lX11 -lm

$(GNL_A):
	$(MAKE) -C $(GNL)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(MLX_A):
	$(MAKE) -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	${MAKE} -C $(GNL) clean
	${MAKE} -C $(LIBFT) clean
	${MAKE} -C $(MLX) clean
	$(RM) $(OBJS)

fclean: clean
	${MAKE} -C $(GNL) fclean
	${MAKE} -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
