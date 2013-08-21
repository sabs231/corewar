/*
** apply_in_list.c for list in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/lib/list
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
** 
** Started on  11/19/12 16:43:40 2012 olivier chapeau
** Last update Mon Dec 10 19:48:10 2012 olivier chapeau
*/

#include "list.h"

void		apply_in_list(t_list *list, void (*f)(void *))
{
  t_link	*tmp;

  if (list == NULL || list->first == NULL || f == NULL)
    return ;
  tmp = list->first;
  while (tmp != NULL)
  {
    (*f)(tmp->data);
    tmp = tmp->next;
  }
}
