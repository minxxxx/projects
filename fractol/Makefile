# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuys <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 11:16:01 by jbuys             #+#    #+#              #
#    Updated: 2016/10/03 10:10:18 by jbuys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

C_FLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

S_P = ./src/

M_P = ./src/Mandelbrot_set/

B_P = ./src/Burningship_set/

J_P = ./src/Julia_set/

SRC = $(S_P)fractol_main.c	$(S_P)init.c \
	  $(MENDELBROT) $(JULIA) $(BURNINGSHIP)\
	  $(S_P)quit.c $(S_P)keypresses.c		\
	  $(S_P)redraw.c						\

MENDELBROT = $(M_P)m_calc.c		

JULIA =	$(J_P)j_calc.c

BURNINGSHIP = $(B_P)b_calc.c

INCLUDES = ./includes/fractol.h

LIBRARY = -L libft/ -lft

OBJ = fractol_main.o			\
	  m_calc.o					\
	  init.o					\
	  quit.o					\
	  j_calc.o					\
	  b_calc.o					\
	  keypresses.o				\
	  redraw.o					\

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(C_FLAGS) -I $(INCLUDES)
	@echo "Creating object files..."
	@gcc -o $(NAME) $(OBJ) $(LIBRARY) $(MLX_FLAGS)
	@echo "Creating Executable..."

clean:
	@rm -f $(OBJ)
	@echo "Removing all OBJ files.."

fclean: clean
	@rm -f $(NAME)
	@echo "Removing executable"

re: fclean all

.norm:
	@norminette $(SRC)
	@echo "\n\nNormed all files"

.db: $(NAME)
	lldb $(NAME)

