/*
** new_link.c for list in /home/chapea_o/travail/corewar/src/my/list
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
** 
** Started on  11/19/12 16:09:38 2012 olivier chapeau
** Last update Fri Dec 07 12:42:13 2012 olivier chapeau
*/

#include "../my.h"
#include "list.h"

t_link		*new_link(void *data)
{
  t_link	*link;

  if ((link = malloc(sizeof(t_link))) == NULL)
  {
    my_fputstr(STDERR, "Memory allocation failed.\n");
    return (NULL);
  }
  link->data = data;
  link->next = NULL;
  return (link);
}
