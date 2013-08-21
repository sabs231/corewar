/*
** my_putstr.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Thu Oct  4 09:48:35 2012 julien regnier
** Last update Mon Dec 03 11:49:14 2012 julien regnier
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_putchar(str[i]) == -1)
        return (-1);
      i = i + 1;
    }
  return (0);
}
