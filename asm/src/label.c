/*
** label.c for src in /home/regnie_j/corewar/src
**
** Made by julien regnier
** Login   <regnie_j@epitech.net>
**
** Started on  Wed Dec 05 18:03:48 2012 julien regnier
** Last update Sat Dec 15 16:00:55 2012 julien regnier
*/

#include <stdio.h>
#include <stdlib.h>
#include "label_struct.h"
#include "my.h"
#include "op.h"
#include "label_utils.h"

int		is_plabel(char *label)
{
  int		i;

  i = 0;
  while ((label[i] != '+' || label[i] != '-')
        && (i < my_strlen(label) - 1))
     i = i + 1;
  return (1);
}

int		is_label(char *label)
{
  int		i;

  i = 0;
  if (label == NULL)
    return (0);
  while (label[i])
  {
    if (i == my_strlen(label) - 1)
    {
      if (label[i] != ':')
        return (0);
      else
        return (1);
    }
    if (valid_char(label[i]) == 0)
      return (0);
    i = i + 1;
  }
  return (0);
}

int		exist(char *label, t_labels *list)
{
  t_labels	*tmp;

  if (list != NULL)
  {
    tmp = list;
    while (tmp)
    {
      if (my_strncmp(label, tmp->label, my_strlen(label)) == 0)
        return (1);
      tmp = tmp->next;
    }
  }
  return (0);
}

int		add_label(char *label, int address, t_labels **list)
{
  t_labels	*new;
  t_labels	*temp;

  new = malloc(sizeof(t_labels));
  if (new == NULL)
    return (0);
  new->label = my_strdup(label);
  if (new->label == NULL)
    return (0);
  new->address = address;
  new->next = NULL;
  if (*list == NULL)
    *list = new;
  else
  {
    temp = *list;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = new;
  }
  return (1);
}

void		free_list(t_labels **list)
{
  t_labels	*temp;

  while (*list)
  {
    temp = *list;
    *list = (*list)->next;
    free(temp->label);
    free(temp);
  }
}
