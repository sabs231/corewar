/*
** my_putchar.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Wed Oct  3 09:41:22 2012 julien regnier
** Last update Mon Dec 03 11:48:57 2012 julien regnier
*/

#include <unistd.h>

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}
