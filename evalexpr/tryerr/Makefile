
CC	= gcc

RM	= rm -f

NAME	= eval_expr

SRCS	= main.c\
	  core_x.c\
	  core.c\
	  operator.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :	
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all
