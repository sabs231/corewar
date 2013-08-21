/*
** my_strlen.c for my_strlen in /home/chapea_o//travail/rendu/lib/
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Thu Oct  4 09:57:54 2012 olivier chapeau
** Last update Thu Oct  4 10:00:14 2012 olivier chapeau
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != '\0')
      i = i + 1;
  return (i);
}
