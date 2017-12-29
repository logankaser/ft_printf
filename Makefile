# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by lkaser            #+#    #+#              #
#    Updated: 2017/12/28 20:13:01 by lkaser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIST = ft_printf format

SRC = $(addsuffix .c, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CFLAGS = -Wall -Wextra -Werror -I libft/includes

all: $(NAME) 

$(NAME): $(OBJ)
	make -C libft
	ar rcs $(NAME) $(OBJ) libft/*.o

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re
