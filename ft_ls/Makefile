# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/11 18:02:12 by ggroener          #+#    #+#              #
#    Updated: 2016/06/14 12:58:51 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c \
			print_directory.c \
			parse_params.c \
			parse_params2.c \
			parse_sources.c \
			load_directory.c \
			directory_add_file.c \
			error_quit.c \
			load_file.c \
			load_file_symb.c \
			load_file_loul.c \
			load_file_perms.c \
			load_file_driver.c \
			load_file_date.c \
			load_file_type.c \
			free_file.c \
			print_file.c \
			add_file.c \
			file_time.c \
			parse_source_push.c \
			parse_sources_empty.c \
			load_file_setinfos.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)
	@echo "Make Done!"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)
	@echo "Compiling Done!"

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C libft/ clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)
	@echo "clean Done!"

fclean: clean
	@make -C libft/ fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)
	@echo "fclean Done!"

re: fclean all
	@echo "re Done!"

.PHONY: clean fclean re odir
