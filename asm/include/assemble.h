/*
** assemble.h for include in /home/regnie_j/corewar/include
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 03 12:05:44 2012 julien regnier
** Last update Sat Dec 15 19:31:32 2012 julien regnier
*/

#ifndef ASSEMBLE_H_
# define ASSEMBLE_H_

typedef struct	s_parser
{
  int		line_nb;
  int		current_address;
}		t_parser;

int	assemble(int fd, char *name);

#endif /* !ASSEMBLE_H_ */
