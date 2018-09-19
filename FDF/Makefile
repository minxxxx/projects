# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 14:36:02 by ggroener          #+#    #+#              #
#    Updated: 2016/06/04 14:36:09 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FILES = build_struct.c draw.c draw_line.c error.c \
		keyhook.c main.c movemap.c point.c \
		point_rotation.c read_file.c
OBJECTS = $(FILES:.c=.o)
CFLAG = -Wall -Werror -Wextra
ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

quick: clean $(NAME)
	@echo "Made Quickly"

lib:
	@make -C libft/ fclean
	@make -C libft/

$(NAME): lib
	@gcc $(CFLAG) -I libft/ -c $(FILES)
	@gcc $(CFLAG) -o $(NAME) $(OBJECTS) $(ATTACH)
	@echo "fdf Successfully Compiled"

clean:
	@/bin/rm -f $(OBJECTS)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	@clear
	@norminette $(FILES)

test:
	@./fdf ../collab_fdf/test_maps/42.fdf
