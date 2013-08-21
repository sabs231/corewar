##
## Makefile for my in /home/regnie_j/corewar/my
##
## Made by julien regnier
## Login   <regnie_j@epitech.net>
##
## Started on  Mon Oct 22 09:03:00 2012 julien regnier
## Last update Sat Dec 15 16:32:52 2012 julien regnier
##

CC	= clang

CFLAGS	= -Wall -pedantic

RM	= rm -f

NAME	= libmy.a

SRCS	= my_str_to_wordtab.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_putstr_err.c \
	  my_strlen.c \
	  my_getnbr.c \
	  my_strcmp.c \
	  my_strncmp.c \
	  my_strncat.c \
	  my_strdup.c \
	  my_strncpy.c \
	  get_next_line.c \
	  my_putnbr_err.c \
	  swap_bytes.c

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
