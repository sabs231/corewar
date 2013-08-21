##
## Makefile for  in /home/baezse_s//svn_corewar/corewar-2016ed-2015s-2017si-baezse_s
## 
## Made by sergioandres baezserrano
## Login   <baezse_s@epitech.net>
## 
## Started on  Sun Dec 16 17:46:21 2012 sergioandres baezserrano
## Last update Sun Dec 16 17:52:16 2012 sergioandres baezserrano
##

ASM_M		=	asm/

VM_M		=	vm/

all:
			make -C $(ASM_M)
			make -C $(VM_M)

clean:
			make clean -C $(ASM_M)
			make clean -C $(VM_M)

fclean:			clean
			make fclean -C $(ASM_M)
			make fclean -C $(VM_M)

re:			fclean all

.PHONY:			all clean fclean re