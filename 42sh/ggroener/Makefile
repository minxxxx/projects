# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/22 11:13:51 by ggroener          #+#    #+#              #
#    Updated: 2016/09/11 12:02:59 by rlutsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

CFLAGS = -Wall -Wextra -Werror -g -g3

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = src/

SRCS_NAME1 =	checks.c \
				command.c \
				count.c \
				errors.c \
			   	exit.c \
				ft_export.c \
			   	ft_strchr_f.c \
				ft_unset.c \
				get_env.c \
				get_line.c \
				main.c \
				own_command.c \
				set_env.c \
				ft_env.c \
				find_path.c \
				ctrl_keys.c \
				dir_manage.c	\

SRCS_NAME2 =	ft_echo.c \
				ft_cd.c \
				trim.c \
				signals.c \
				init_term.c \
				init_term2.c \
			   	debug.c \
				get_input.c \
				com_history.c \
			  	ft_cd_sub.c \
				keys.c \
				keys_lr.c \
				easteregg.c \
				keys_he.c \
				keys_w_jump.c \
				keys_del.c \
				keys_cb.c \
				check_par.c \
			   	cursor.c \
				list_history.c\
				auto_complete.c	\


SRCS_NAME3 = 	ft_unit_len.c \
				init_structs.c \
				sub_var.c		\
				ft_lexer.c 			\
				ft_read_path.c 		\
				check_pipes.c  		\
				create_path.c 		\
				ft_execve.c 		\
				ft_get_pipe_path.c 	\
				ft_make_pipelst.c 	\
				ft_pipecode_path.c 	\
				ft_and.c 			\
				ft_ar_lft.c 		\
				ft_ar_rgt.c 		\
				read_left_path.c 	\
				ft_sigleton.c 		\
				ft_jumprint.c 		\
				re_malloc.c		\
				sort_history.c	\

SRCS_NAME4 =	get_winsize.c		\
				ft_create_string.c  \
				ft_write_on_file.c	\
				l_list.c			\
				ft_putcur.c 		\
				read_right_path.c 	\
				read_left_path_tool.c \
				ft_create_hst.c 	\
				ft_clean_hist.c		\
				pipe.c 				\
				ft_split.c 			\
				is_operands.c 		\
				ft_fill_tab.c 		\
				ft_or.c 			\
				ft_semicol.c 		\
				ft_filled_lste.c 	\
				ft_tputs.c 		 	\
				link_files.c		\

SRCS4 = $(addprefix $(SRCS_PATH), $(SRCS_NAME4))

SRCS3 = $(addprefix $(SRCS_PATH), $(SRCS_NAME3))

SRCS2 = $(addprefix $(SRCS_PATH), $(SRCS_NAME2))

SRCS1 = $(addprefix $(SRCS_PATH), $(SRCS_NAME1))

SRCS = $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4)

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME1:.c=.o) $(SRCS_NAME2:.c=.o) $(SRCS_NAME3:.c=.o) $(SRCS_NAME4:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft -ltermcap

INCLUDES = -I includes/ -I libft/includes

HEADER = 	$(INCLUDES_PATH)minishell.h \
			$(INCLUDES_PATH)pipe.h \

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
	@clear
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)
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
	@norminette $(SRCS1)
	@norminette $(SRCS2)
	@norminette $(SRCS3)
	@norminette	$(SRCS4)
	@norminette $(HEADER)

norme: norm

qme:
	@if [ ! -f author ];then \
			echo cdebruyn > author;echo ggroener >> author;echo khansman >> author;\
			echo jlangman >> author;echo rlutsch >> author;\
		fi

full: re clean
	@./$(NAME)

me: qme
	cat -e author

.PHONY: clean fclean re odir
