/*
** delete.c for list in /home/chapea_o/travail/corewar/src/my/list
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
** 
** Started on  11/19/12 16:30:24 2012 olivier chapeau
** Last update Fri Dec 07 12:09:22 2012 olivier chapeau
*/

#include "list.h"

void		*delete_first(t_list *list)
{
  void		*data;
  t_link	*tmp;

  if (list == NULL || list->first == NULL)
    return (NULL);
  tmp = list->first->next;
  data = list->first->data;
  free(list->first);
  list->first = tmp;
  return (data);
}
