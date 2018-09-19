# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/09/02 13:57:15 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: $(NAME)

$(NAME):
	make -C src_asm/
	make -C src_vm/
	echo "derp"
	cp src_vm/corewar .
	cp src_asm/asm .

clean:
	make clean -C src_asm/
	make clean -C src_vm/

fclean:
	make fclean -C src_asm/
	make fclean -C src_vm/
	/bin/rm -f asm
	/bin/rm -f corewar

re: 
	make re -C src_asm/
	make re -C src_vm/
	cp src_vm/corewar .
	cp src_asm/asm .

format: me

qme:
	@rm -Rf author
	@echo daviwel > author
	@echo ddu-toit >> author
	@echo vivan-de >> author
	@echo ggroener >> author

me: qme
	cat -e author
