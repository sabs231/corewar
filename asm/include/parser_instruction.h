/*
** parser_instruction.h for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Tue Dec 04 10:45:50 2012 julien regnier
** Last update Wed Dec 12 12:18:46 2012 julien regnier
*/

#ifndef PARSER_INSTRUCTION_H_
# define PARSER_INSTRUCTION_H_

# include "label_struct.h"

int	parse_instruction(int fd_src, t_parser *parser, t_labels **list);
void	free_tab(char **my_tab);

#endif /* !PARSER_INSTRUCTION_H_ */
