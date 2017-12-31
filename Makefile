# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by lkaser            #+#    #+#              #
#    Updated: 2017/12/30 16:35:37 by lkaser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIST = ft_printf format

SRC = $(addsuffix .c, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CFLAGS = -O3 -Wall -Wextra -Werror -I libft/includes

all: $(NAME) 

$(NAME): $(OBJ)
	make -C libft
	@gcc -c $(SRC) $(CFLAGS)
	@ar rcs $(NAME) libft/*.o $(OBJ) && echo "\033[32;1mlibftprintf.a Created\033[0m"

test:
	gcc $(CFLAGS) -L. -lftprintf test.c -o test
	./test

clean:
	@echo "\033[31;1mCleaning..\033[0m"
	make -C libft clean
	@rm -f $(OBJ) test.o

fclean:
	@echo "\033[31;1mFull Cleaning..\033[0m"
	make -C libft fclean
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f test

re:	fclean all

.PHONY: clean fclean all re
