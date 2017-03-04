##
## Makefile for  in /home/yannick.suc/rush/rush1/task2
## 
## Made by suc yannick
## Login   <yannick.suc@epitech.net>
## 
## Started on  Sat Mar  4 11:51:38 2017 suc yannick
## Last update Sat Mar  4 12:00:34 2017 suc yannick
##

CC	=	gcc

RM	=	rm -f

FLAGS	+=	

CPPFLAGS	+=	-I include/

CFLAGS	+=	-Wextra -Werror -Wall

NAME_A	=	my_archive

NAME_U	=	my_unarchive

SRCS_A	=	my_archive.c	\
		my_strcat.c	\
		get_next_line.c

SRCS_U	=	my_unarchive.c	\
		my_strcat.c	\
		get_next_line.c

OBJS_A	=	$(SRCS_A:.c=.o)

OBJS_U	=	$(SRCS_U:.c=.o)

all:	$(NAME_A) $(NAME_U)

$(NAME_A):	$(OBJS_A)
	$(CC) $(OBJS_A) -o $(NAME_A) $(FLAGS)

$(NAME_U):	$(OBJS_U)
	$(CC) $(OBJS_U) -o $(NAME_U) $(FLAGS)

clean:
	$(RM) $(OBJS_A)
	$(RM) $(OBJS_U)

fclean:	clean
	$(RM) $(NAME_A)
	$(RM) $(NAME_U)

re:	fclean all

.PHONY:	all clean fclean re
