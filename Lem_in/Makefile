# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/19 06:43:27 by ggroener          #+#    #+#              #
#    Updated: 2016/07/24 14:50:45 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

CFLAGS = -Wall -Wextra -Werror -g3 -Ofast -pedantic

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c \
			reader.c \
			read_link.c \
			error_quit.c \
			create_room.c \
			read_room.c \
			place_points.c \
			print_moves.c \
			valid_int.c \
			add_file_line.c \
			print_file.c \
			del_links.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft

HEADER = $(INCLUDES_PATH)env.h \
		 $(INCLUDES_PATH)includes.h \
		 $(INCLUDES_PATH)prototypes.h \
		 $(INCLUDES_PATH)lem_in.h \
		 $(INCLUDES_PATH)reader.h \
		 $(INCLUDES_PATH)room.h \
		 $(INCLUDES_PATH)room_list.h \

all: qme odir $(NAME)

define colourecho
	@tput setaf 14
	@echo $1
	@tput sgr0
endef

define colourecho2
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

$(NAME): $(OBJS)
	@Make -C libft
	@$(call colourecho, " - Making $(NAME)")
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)
	@$(call colourecho, "Compiling Done!")

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@Make clean -C libft
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@$(call colourecho, "clean done!")

fclean: clean
	@Make fclean -C libft
	@$(call colourecho, "Clearing executable files")
	@rm -f $(NAME)
	@$(call colourecho, "fclean done")

re: fclean all
	@$(call colourecho, "re Done!")

format: norm me

norm:
	@clear
	@$(call colourecho2, "Norminette:")
	@norminette $(SRCS)
	@norminette $(HEADER)

qme:
	@rm -Rf author
	@whoami > author
	
me: qme
	cat -e author

.PHONY: clean fclean re odir
