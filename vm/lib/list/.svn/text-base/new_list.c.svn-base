/*
** new_list.c for list in /home/chapea_o/travail/corewar/src/my/list
**
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
**
** Started on  11/19/12 17:14:58 2012 olivier chapeau
** Last update Fri Dec 07 12:42:07 2012 olivier chapeau
*/

#include "../my.h"
#include "list.h"

t_list		*new_list(void)
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
  {
    my_fputstr(STDERR, "Memory allocation failed.\n");
    return (NULL);
  }
  list->first = NULL;
  return (list);
}
