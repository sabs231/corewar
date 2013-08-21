/*
** my_strlen.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Thu Oct  4 09:57:44 2012 julien regnier
** Last update Mon Dec 03 11:27:53 2012 julien regnier
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int		len;

  len = 0;
  while (str != NULL && str[len] != 0)
    len = len + 1;
  return (len);
}
