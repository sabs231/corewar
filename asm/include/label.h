/*
** label.h for include in /home/regnie_j/corewar/include
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Wed Dec 05 18:08:16 2012 julien regnier
** Last update Sat Dec 15 19:32:26 2012 julien regnier
*/

#ifndef LABEL_H_
# define LABEL_H_

# include "label_struct.h"

int	is_label(char *label);
int	is_plabel(char *label);
int	exist(char *label, t_labels *list);
int	add_label(char *label, int address, t_labels **list);
void	free_list(t_labels **list);

#endif /* !LABEL_H_ */
