/*
** instruction.h for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Wed Dec 05 18:11:24 2012 julien regnier
** Last update Wed Dec 12 17:39:41 2012 julien regnier
*/

#ifndef INSTRUCTION_H_
# define INSTRUCTION_H_

int	get_param_number(char *cmd);
int	is_number_valid(char **words, char *command);
int	is_defined(char *s);
int	get_incsize(char **my_tab);

#endif /* !INSTRUCTION_H_ */
