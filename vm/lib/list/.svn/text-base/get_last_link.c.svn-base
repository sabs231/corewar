/*
** get_last_link.c for list in /home/chapea_o/travail/corewar/src/my/list
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Dec 10 15:20:08 2012 olivier chapeau
** Last update Mon Dec 10 15:27:55 2012 olivier chapeau
*/

#include "list.h"

t_link		*get_last_link(t_list *list)
{
  t_link	*tmp;

  if (list == NULL)
    return (NULL);
  tmp = list->first;
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (tmp);
}
