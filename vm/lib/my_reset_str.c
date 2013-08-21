/*
** my_reset_str.c for my_reset_str.c in /home/chapea_o/travail/rendu/mysh/my_reset_str.c
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.eu>
** 
** Started on  11/05/12 19:24:52 2012 olivier chapeau
** Last update 11/05/12 19:24:52 2012 olivier chapeau
*/

#include <stdlib.h>
#include "my.h"

void	my_reset_str(char *str)
{
  while (str != NULL && *str != '\0')
  {
    *str = '\0';
    str = str + 1;
  }
}
