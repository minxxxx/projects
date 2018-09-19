# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/22 11:13:09 by ggroener          #+#    #+#              #
#    Updated: 2016/07/17 10:44:27 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CFLAGS = -Wall -Wextra -Werror -g3 #-pedantic #-Ofast -ltermcap

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = caption.c \
			center.c \
			check.c \
			choice.c \
			clear.c \
			cmdgoto.c \
			cmdput.c \
			cmdstr.c \
			colour.c \
			columns.c \
			decal.c \
			delmenu.c \
			ft_select.c \
			getch.c \
			getkey.c \
			init.c \
			putchoice.c \
			putcirc.c \
			putmenu.c \
			putstr.c \
			scan.c \
			search.c \
			signal.c \
			sound.c \
			termsize.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft -ltermcap

HEADER = $(INCLUDES_PATH)choice.h \
		 $(INCLUDES_PATH)includes.h \
		 $(INCLUDES_PATH)prototypes.h \
		 $(INCLUDES_PATH)ft_select.h \
		 $(INCLUDES_PATH)t_v_arg.h \
		 $(INCLUDES_PATH)putmenu.h \
		 $(INCLUDES_PATH)search.h \

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
	@rm -f $(OBJS)
	@clear
	@echo "clean Done!"

fclean: clean
	@Make fclean -C libft
	@echo " - Clearing executable file"
	@rm -f $(NAME)
	@clear
	@echo "fclean Done!"

re: fclean all
	@echo "re Done!"

format: norm me

norm:
	@clear
	@echo "Norminette:"
	@norminette $(SRCS)
	@norminette $(HEADER)

qme:
	@rm -Rf author
	@whoami > author
	
me: qme
	cat -e author

.PHONY: clean fclean re odir
