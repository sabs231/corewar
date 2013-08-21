/*
** my_put_nbr.c for  in /home/baezse_s//git_corewar/corewar/vm
** 
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
** 
** Started on  Mon Dec 10 16:33:26 2012 sergioandres baezserrano
** Last update Mon Dec 10 16:55:03 2012 sergioandres baezserrano
*/

#include "my.h"

void	my_put_nbr(int	nbr)
{
  int	module;

  if (nbr < 0)
    {
      nbr *= -1;
      my_putchar('-');
    }
  if (nbr < 10)
    {
      module = nbr % 10;
      my_putchar('0');
      my_putchar('0' + module);
    }
  else
    {
      my_put_nbr(nbr / 10);
      module = nbr % 10;
      my_putchar('0' + module);
    }
}
