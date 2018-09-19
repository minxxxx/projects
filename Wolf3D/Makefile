# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/22 11:13:51 by ggroener          #+#    #+#              #
#    Updated: 2016/06/23 12:48:19 by khansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror -Ofast -g

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = wolf3d.c \
			draw.c \
			env_init.c \
			error_quit.c \
			event_listener.c \
			movements.c \
			pixel_put.c \
			window_init.c \
			map_load.c \
			file_length.c \
			get_file_content.c \
			place_player.c \
			put_fps.c \
			time_elapse.c \
			exit.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

HEADER = 	$(INCLUDES_PATH)colour.h \
			$(INCLUDES_PATH)includes.h \
			$(INCLUDES_PATH)prototypes.h \
			$(INCLUDES_PATH)ray_data.h \
			$(INCLUDES_PATH)window.h \
			$(INCLUDES_PATH)env.h \
			$(INCLUDES_PATH)map.h \
			$(INCLUDES_PATH)ray.h \
			$(INCLUDES_PATH)vector.h \
			$(INCLUDES_PATH)wolf3d.h

all: qme odir $(NAME)

$(NAME): $(OBJS)
	@Make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)
	@clear
	@echo "Make Done!"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)
	@echo "Compiling Done!"

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@Make clean -C libft
	@echo " - Clearing objects files"
	@rm -Rf $(OBJS_PATH)
	@echo "clean Done!"

fclean: clean
	@Make fclean -C libft
	@echo " - Clearing executable file"
	@rm -f $(NAME)
	@echo "fclean Done!"

re: fclean all
	@echo "re Done!"

format: norme me

norme:
	@clear
	@echo "Norminette:"
	@norminette $(SRCS) 
	@norminette $(HEADER)

me: qme
	@echo "\nAuthor:"
	cat -e author

qme:
	@rm -Rf author
	@whoami > author

.PHONY: clean fclean re odir
