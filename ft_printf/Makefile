# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 14:36:02 by ggroener          #+#    #+#              #
#    Updated: 2016/06/05 15:22:00 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_intlen.c ft_printf_long.c ft_printf_hex.c \
		ft_printf.c ft_printf_nbr_ld.c ft_printf_diff.c \
		ft_strlen.c ft_putchar.c ft_toupper.c ft_putstr.c ft_putnbr.c \
	    ft_putnbr_fd.c ft_putnbr.c 
OBJECTS = $(FILES:.c=.o)
CFLAG = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME): 
	@gcc $(CFLAG) $(FILES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "printf Successfully Compiled"

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

norme:
	@clear
	@norminette $(FILES)

test:
	@./printf test.c
