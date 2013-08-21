/*
** is_empty.c for list in /home/chapea_o/travail/corewar/src/my/list
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
** 
** Started on  11/19/12 16:35:29 2012 olivier chapeau
** Last update Fri Dec 07 12:12:30 2012 olivier chapeau
*/

#include "list.h"

int	        is_empty_list(t_list *list)
{
  return (!size_list(list));
}
