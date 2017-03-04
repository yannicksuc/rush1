## /*********************************************\
## |*  Makefile created by AutoHeader v. 0.4.2  *|
## |* https://github.com/FantinBibas/autoHeader *|
## \*********************************************/

CC	=	gcc

RM	=	rm -f

FLAGS	+=	

CPPFLAGS	+=	-I include/

CFLAGS	+=	-Wextra -Werror -Wall

NAME	=	my_unarchive

SRCS	=	get_next_line.c	\
		my_strcat.c	\
		my_unarchive.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

