/*
** label_utils.c for src in /home/regnie_j/corewar/src
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Dec 05 19:07:08 2012 Marin Alcaraz
** Last update Sat Dec 15 16:15:27 2012 julien regnier
*/

#include <stdio.h>
#include "op.h"
#include "my.h"
#include "label_struct.h"

int	valid_char(char c)
{
  int	i;

  i = 0;
  while (i <= my_strlen(LABEL_CHARS))
  {
    if (c == LABEL_CHARS[i])
      return (1);
    i = i + 1;
  }
  return (0);
}

int	purgue_number(char *s)
{
  int	i;

  i = 0;
  while (((s[i] != '+' && s[i] != '-')) && s[i] != '\0')
    i = i + 1;
  return (i);
}

int	get_add_lab(char *label, t_labels *list)
{
  t_labels	*tmp;

  if (list != NULL)
  {
    tmp = list;
    while (tmp)
    {
      if (my_strncmp(label, tmp->label, my_strlen(label)) == 0
          && tmp->label[my_strlen(label)] == LABEL_CHAR)
        return (tmp->address);
      tmp = tmp->next;
    }
  }
  return (-1);
}
