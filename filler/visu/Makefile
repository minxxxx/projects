# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/10 11:38:56 by ggroener          #+#    #+#              #
#    Updated: 2016/06/10 11:39:00 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs

INCPATH = ./includes

LIBFT = ../libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)

LIB = -L$(LIBFT) -lft -lncurses

SRC = 	$(SRCPATH)/main.c\
		$(SRCPATH)/ft_set_data.c\
		$(SRCPATH)/ft_util.c\
		$(SRCPATH)/ft_ncurses.c\
		$(SRCPATH)/ft_nc_init.c\

OBJ = $(SRC:.c=.o)

NAME = visu

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(HEADER) $(LIB) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[35m█\033[0m\c"

clean : 
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ)

fclean : clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
