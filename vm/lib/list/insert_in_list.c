/*
** insert.c for list in /home/chapea_o/travail/corewar/src/my/list
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
** 
** Started on  11/19/12 16:15:10 2012 olivier chapeau
** Last update Sun Dec  9 11:09:37 2012 sergioandres baezserrano
*/

#include "list.h"

void		insert_in_list(t_list *list, void *data)
{
  t_link	*link;
  t_link	*tmp;

  if (list == NULL || data == NULL)
    return ;
  if ((link = new_link(data)) == NULL)
    return ;
  if (list->first == NULL)
  {
    list->first = link;
  }
  else
  {
    tmp = list->first;
    while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
    tmp->next = link;
  }
}
