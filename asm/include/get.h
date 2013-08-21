/*
** get.h for include in /home/regnie_j/corewar/include
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 03 12:45:01 2012 julien regnier
** Last update Sat Dec 15 19:32:00 2012 julien regnier
*/

#ifndef GET_H_
# define GET_H_

# include "assemble.h"

int	get_nb_args_mnemonique(char *mnemonique);
char	*get_new_name(char *name);
char	*get_next_instruction(int fd_src, t_parser *parser);
char	*get_first_word(char *str);

#endif /* !GET_H_ */
