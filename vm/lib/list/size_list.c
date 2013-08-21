/*
** size_list.c for list in /home/chapea_o/travail/corewar/src/my/list
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
** 
** Started on  11/19/12 16:32:32 2012 olivier chapeau
** Last update Fri Dec 07 12:11:35 2012 olivier chapeau
*/

#include "list.h"

int		size_list(t_list *list)
{
  int		size;
  t_link	*tmp;

  size = 0;
  if (list == NULL || list->first == NULL)
    return (size);
  tmp = list->first;
  while (tmp != NULL)
  {
    size = size + 1;
    tmp = tmp->next;
  }
  return (size);
}
