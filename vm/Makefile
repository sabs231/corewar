##
## Makefile for vm in /home/chapea_o/travail/corewar/git_corewar/corewar/vm
##
## Made by olivier chapeau
## Login   <chapea_o@epitech.net>
##
## Started on  Mon Oct 22 10:32:07 2012 olivier chapeau
## Last update Sun Dec 16 17:17:34 2012 olivier chapeau
##

INCLUDE		= include/

SOURCES		= src/

LIB_PATH	= lib/

LIST_PATH	= $(LIB_PATH)list/

CC		= clang

CFLAGS		= -Wall -Wextra -ansi -pedantic -Werror -I$(LIB_PATH) -I$(LIST_PATH) -I$(INCLUDE)

LDFLAGS		= -L$(LIB_PATH) $(LDLIBS)

LDLIBS		= -lmy

NAME		= corewar

SRCS		= $(SOURCES)main.c			\
		  $(SOURCES)vm_init.c 			\
		  $(SOURCES)vm_destroy.c 		\
		  $(SOURCES)vm_errors.c			\
		  $(SOURCES)vm_files.c			\
		  $(SOURCES)vm_warriors.c		\
		  $(SOURCES)vm_processes.c		\
		  $(SOURCES)vm_options.c		\
		  $(SOURCES)vm_get_options.c		\
		  $(SOURCES)op.c 			\
		  $(SOURCES)vm_read_files.c 		\
		  $(SOURCES)endianness.c 		\
		  $(SOURCES)vm_functions.c		\
		  $(SOURCES)vm_load_champ.c

OBJS		= $(SRCS:.c=.o)

RM		= rm -f

all:	 $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_PATH)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	make clean -C $(LIB_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIB_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
