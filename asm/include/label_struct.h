/*
** label_struct.h for include in /home/regnie_j/corewar/include
**
** Made by julien regnier
** Login   <regnie_j@epitech.net>
**
** Started on  Wed Dec 05 17:47:42 2012 julien regnier
** Last update Wed Dec 05 18:37:18 2012 julien regnier
*/

#ifndef LABEL_STRUCT_H_
# define LABEL_STRUCT_H_

typedef struct		s_labels
{
  char			*label;
  int			address;
  struct s_labels	*next;
}			t_labels;

#endif /* !LABEL_STRUCT_H_ */
