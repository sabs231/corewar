##
## Makefile for lib in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/lib
##
## Made by olivier chapeau
## Login   <chapea_o@epitech.net>
##
## Started on  Mon Oct 22 09:18:41 2012 olivier chapeau
## Last update Sun Dec 16 17:08:11 2012 olivier chapeau
## Last update Mon Dec 10 16:44:11 2012 sergioandres baezserrano
##

CC	= clang

CFLAGS	= -Wall -Wextra -ansi -pedantic -Werror

NAME	= libmy.a

LIST	= list/

SRCS	= $(LIST)new_list.c		\
	  $(LIST)new_link.c		\
	  $(LIST)insert_in_list.c	\
	  $(LIST)delete_first.c 	\
	  $(LIST)get_last_link.c 	\
	  $(LIST)size_list.c 		\
	  $(LIST)is_empty_list.c 	\
	  $(LIST)apply_in_list.c	\
	  $(LIST)clear_list.c		\
	  my_reset_str.c		\
	  my_fputstr.c			\
	  my_putchar.c			\
	  my_fputchar.c			\
	  my_fputnbr.c			\
	  my_putstr.c			\
	  my_strlen.c			\
	  my_revstr.c			\
	  my_strcmp.c			\
	  my_strncmp.c			\
	  my_strcpy.c			\
	  my_strncpy.c			\
	  my_get_unsigned_nbr.c		\
	  my_putnbr_base.c		\
	  my_put_nbr.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)
	 ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
