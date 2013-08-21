/*
** my_putstr_err.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Thu Oct  4 09:48:35 2012 julien regnier
** Last update Mon Dec 03 11:52:12 2012 julien regnier
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_putchar_err(char c, int fd)
{
  if (write(fd, &c, 1) == -1)
    return (-1);
  return (0);
}

int	my_putstr_err(char *str, int fd)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_putchar_err(str[i], fd) == -1)
        return (-1);
      i = i + 1;
    }
  return (0);
}
