##
## Makefile for corewar in /home/regnie_j/corewar
##
## Made by julien regnier
## Login   <regnie_j@epitech.net>
##
## Started on  Thu Oct 25 11:07:35 2012 julien regnier
## Last update Sat Dec 15 19:17:07 2012 julien regnier
##

SOURCES		= src/

INCLUDE		= include/

LIB_PATH	= my/

CC		= clang

CFLAGS		= -Wextra -Werror -Wall -pedantic -ansi -I$(LIB_PATH) -I$(INCLUDE)

NAME		= asm

LIB		= -L$(LIB_PATH) -lmy

SRCS		= $(SOURCES)main.c 		\
		  $(SOURCES)op.c 		\
		  $(SOURCES)assemble.c 		\
		  $(SOURCES)get.c 		\
		  $(SOURCES)parser_header.c 	\
		  $(SOURCES)error.c 		\
		  $(SOURCES)parser_instruction.c\
		  $(SOURCES)label.c 		\
		  $(SOURCES)instruction.c 	\
		  $(SOURCES)label_utils.c 	\
		  $(SOURCES)arg_utils.c 	\
		  $(SOURCES)compressor.c 	\
		  $(SOURCES)parser_translate.c 	\
		  $(SOURCES)write_instruction.c \
		  $(SOURCES)write_bytes.c 	\
		  $(SOURCES)encoding_byte.c 	\
		  $(SOURCES)get_addr.c		\
		  $(SOURCES)write_argument.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_PATH)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re:	fclean all
