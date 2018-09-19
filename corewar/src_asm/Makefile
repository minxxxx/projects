# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/29 09:15:12 by daviwel           #+#    #+#              #
#    Updated: 2016/08/28 12:34:03 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = main.c \
	  error_check.c \
	  store_input.c \
	  validate_input.c \
	  validate_n_c.c \
	  start_compile.c \
	  init_header.c \
	  reverse_bytes.c \
	  write_file.c \
	  print_mem.c \
	  read_line.c \
	  check_label.c \
	  fill_optab.c \
	  fill_subfunc.c \
	  interpret_line.c \
	  get_command.c \
	  check_n_c.c \
	  check_command.c \
	  store_params.c \
	  str_trim.c \
	  create_command.c \
	  count_arr.c \
	  get_encoding_byte.c \
	  check_param.c \
	  get_param_bytes.c \
	  return_param_type.c \
	  write_commands.c \
	  find_label_line.c \
	  count_bytes_between.c \
	  free_info_label.c \
	  free_input.c \
	  free_commands.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra -g3

INCLUDES = -I ../includes -I ../libft/includes

ATTACH = -L ../libft -lft

all: qme $(NAME)

$(NAME):
	gcc $(CFLAG) $(INCLUDES) -c $(SRC)
	gcc $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f *.cor

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC) ../includes

format: me

qme:
	@rm -Rf author
	@echo daviwel > author
	@echo ddu-toit >> author
	@echo vivan-de >> author
	@echo ggroener >> author

me: qme
	cat -e author
