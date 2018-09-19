# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/22 11:13:09 by ggroener          #+#    #+#              #
#    Updated: 2016/07/03 09:47:49 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -Ofast

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c \
			parse_args.c \
			valid_int.c \
			error_quit.c \
			calc_sorted.c \
			check_dur.c \
			pre_sort.c \
			sort.c \
			sort_3.c \
			sort_5.c \
			print_a.c \
			is_sorted.c \
			print_b.c \
			sa.c \
			sb.c \
			ss.c \
			pa.c \
			pb.c \
			ra.c \
			rb.c \
			rr.c \
			rra.c \
			rrb.c \
			rrr.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft

HEADER = $(INCLUDES_PATH)env.h \
		 $(INCLUDES_PATH)includes.h \
		 $(INCLUDES_PATH)prototypes.h \
		 $(INCLUDES_PATH)push_swap.h \
		 $(INCLUDES_PATH)sort.h \

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
	cat -a author

.PHONY: clean fclean re odir
