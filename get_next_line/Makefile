# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 11:45:41 by vketteni          #+#    #+#              #
#    Updated: 2024/02/04 11:47:52 by vketteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRS = get_next_line.c get_next_line_utils.c
OBJS = $(SCRS:.c=.o)
NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
INC = get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
