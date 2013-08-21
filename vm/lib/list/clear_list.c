/*
** clear_list.c for list in /home/chapea_o/travail/corewar/src/my/list
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
** 
** Started on  11/19/12 16:38:41 2012 olivier chapeau
** Last update Fri Dec 07 16:58:00 2012 olivier chapeau
*/

#include "list.h"

void		clear_list(t_list **list)
{
  t_link	*tmp;

  if (list == NULL || *list == NULL)
    return ;
  if ((*list)->first == NULL)
  {
    free(*list);
    *list = NULL;
    return ;
  }
  while ((*list)->first != NULL)
  {
    tmp = (*list)->first->next;
    free((*list)->first);
    (*list)->first = tmp;
  }
  free(*list);
  *list = NULL;
}
