# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/15 07:50:12 by ggroener          #+#    #+#              #
#    Updated: 2016/09/11 13:00:20 by cdebruyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast -g3 -pedantic

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = ft_itoa_base.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strjoin_free1.c \
			ft_strjoin_free2.c \
			ft_strjoin_free3.c \
			ft_atod.c \
			ft_strcount.c \
			ft_strisdigit.c \
			ft_ltoa.c \
			ft_ultoa.c \
			ft_ltoa_base.c \
			ft_ultoa_base.c \
			ft_putwchar.c \
			ft_putwchar_fd.c \
			ft_putwstr.c \
			ft_putwstr_fd.c \
			ft_wstrlen.c \
			ft_wstrsub.c \
			ft_atol.c \
			ft_putul.c \
			ft_putul_fd.c \
			ft_strsub_free.c \
			ft_strtrim_free.c \
			ft_exit.c \
			get_next_line.c \
			ft_check_literal.c \
			ft_replace_literal.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

define colourecho
	@tput setaf 4
	@echo $1
	@tput sgr0
endef

all: odir $(NAME)

$(NAME): $(OBJS)
	@$(call colourecho, " - Making $(NAME)")
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@$(call colourecho, " - Clearing Objects")
	@rm -f $(OBJS)

fclean: clean
	@$(call colourecho, " - Cleaning Executable")
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
