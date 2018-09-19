# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuys <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/21 12:23:23 by jbuys             #+#    #+#              #
#    Updated: 2016/08/12 13:40:00 by jbuys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FLAGS = -Wall -Wextra -Werror -std=c99

S_P = ./src/

SRC =  $(S_P)ft_memset.c	\
	   $(S_P)ft_bzero.c 	\
	   $(S_P)ft_memcpy.c	\
	   $(S_P)ft_memccpy.c	\
	   $(S_P)ft_memmove.c	\
	   $(S_P)ft_memchr.c	\
	   $(S_P)ft_memcmp.c	\
	   $(S_P)ft_strlen.c	\
	   $(S_P)ft_strdup.c	\
	   $(S_P)ft_strcpy.c	\
	   $(S_P)ft_strncpy.c	\
	   $(S_P)ft_strcat.c	\
	   $(S_P)ft_strncat.c	\
	   $(S_P)ft_strlcat.c	\
	   $(S_P)ft_strchr.c	\
	   $(S_P)ft_strrchr.c	\
	   $(S_P)ft_strstr.c	\
	   $(S_P)ft_strnstr.c	\
	   $(S_P)ft_strcmp.c	\
	   $(S_P)ft_strncmp.c	\
	   $(S_P)ft_atoi.c		\
	   $(S_P)ft_isalpha.c	\
	   $(S_P)ft_isdigit.c	\
	   $(S_P)ft_isalnum.c	\
	   $(S_P)ft_isascii.c	\
	   $(S_P)ft_isprint.c	\
	   $(S_P)ft_toupper.c	\
	   $(S_P)ft_tolower.c	\
	   $(S_P)ft_memalloc.c	\
	   $(S_P)ft_memdel.c	\
	   $(S_P)ft_strnew.c	\
	   $(S_P)ft_strdel.c	\
	   $(S_P)ft_strclr.c	\
	   $(S_P)ft_striter.c	\
	   $(S_P)ft_striteri.c	\
	   $(S_P)ft_strmap.c	\
	   $(S_P)ft_strmapi.c	\
	   $(S_P)ft_strequ.c	\
	   $(S_P)ft_strnequ.c	\
	   $(S_P)ft_strjoin.c	\
	   $(S_P)ft_strtrim.c	\
	   $(S_P)ft_strsplit.c	\
	   $(S_P)ft_itoa.c		\
	   $(S_P)ft_putchar.c	\
	   $(S_P)ft_putchar_fd.c\
	   $(S_P)ft_putstr.c	\
	   $(S_P)ft_putstr_fd.c	\
	   $(S_P)ft_putendl.c	\
	   $(S_P)ft_putendl_fd.c\
	   $(S_P)ft_putnbr.c	\
	   $(S_P)ft_putnbr_fd.c	\
	   $(S_P)ft_strsub.c	\
	   $(S_P)get_next_line.c\
	   $(S_P)do_flags.c		\
	   $(S_P)ft_convert.c	\
	   $(S_P)ft_count_ui_num.c	\
	   $(S_P)ft_printf.c	\


OBJ =  ft_memset.o		\
	   ft_bzero.o 		\
	   ft_memcpy.o		\
	   ft_memccpy.o		\
	   ft_memmove.o	\
	   ft_memchr.o		\
	   ft_memcmp.o		\
	   ft_strlen.o		\
	   ft_strdup.o		\
	   ft_strcpy.o		\
	   ft_strncpy.o		\
	   ft_strcat.o		\
	   ft_strncat.o		\
	   ft_strlcat.o		\
	   ft_strchr.o		\
	   ft_strrchr.o		\
	   ft_strstr.o		\
	   ft_strnstr.o		\
	   ft_strcmp.o		\
	   ft_strncmp.o		\
	   ft_atoi.o		\
	   ft_isalpha.o		\
	   ft_isdigit.o		\
	   ft_isalnum.o		\
	   ft_isascii.o		\
	   ft_isprint.o		\
	   ft_toupper.o		\
	   ft_tolower.o		\
	   ft_memalloc.o	\
	   ft_memdel.o		\
	   ft_strnew.o		\
	   ft_strdel.o		\
	   ft_strclr.o		\
	   ft_striter.o		\
	   ft_striteri.o	\
	   ft_strmap.o		\
	   ft_strmapi.o		\
	   ft_strequ.o		\
	   ft_strnequ.o		\
	   ft_strjoin.o		\
	   ft_strtrim.o		\
	   ft_strsplit.o	\
	   ft_itoa.o		\
	   ft_putchar.o		\
	   ft_putchar_fd.o	\
	   ft_putstr.o		\
	   ft_putstr_fd.o	\
	   ft_putendl.o		\
	   ft_putendl_fd.o	\
	   ft_putnbr.o		\
	   ft_putnbr_fd.o	\
	   ft_strsub.o		\
	   get_next_line.o	\
	   do_flags.o		\
	   ft_convert.o		\
	   ft_count_ui_num.o\
	   ft_printf.o		\



INCLUDES = ./includes/libft.h

all: $(NAME)

$(NAME):
	@gcc -c $(C_FLAGS) $(SRC) -I $(INCLUDES)
	@echo "\033[0;34mCompiling OBJ files... \033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;34mCreated and Running Library \033[0m"

clean:
	@rm -f $(OBJ)
	@echo "Removing All Object files..."

fclean: clean
	@rm -f $(NAME)
	@echo "Removing Library"

re: fclean all

.norm:
	norminette $(SRC)
