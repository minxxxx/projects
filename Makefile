# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/16 10:17:19 by amkhuma           #+#    #+#              #
#    Updated: 2017/11/05 14:14:19 by amkhuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SOURCES = sources/main.c\
		  sources/image.c\
		  sources/keyboard.c\
		  sources/fractols.c\
		  sources/init.c


HEADER = -I include

LFLAGS = -L./libft/ -lft

FLAGS = -o fractol -Wall -Werror -Wextra

all:
		@make -C libft/
		@gcc $(FLAGS) $(SOURCES) $(HEADER) $(LFLAGS) -lmlx -framework OpenGL -framework AppKit
		@echo "\033[00;32mMade '$(NAME)'\033[0m"

clean:
		@rm $(NAME)
		@make -C libft/ clean

fclean: clean
		@rm -rf $(NAME)
		@rm -rf libft/libft.a
		@echo "\033[00;32mRemoved '$(NAME)'"

re: fclean all
