/*
** my_putnbr_base.c for  in /home/baezse_s//git_corewar/corewar/vm
** 
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
** 
** Started on  Mon Dec 10 16:23:25 2012 sergioandres baezserrano
** Last update Mon Dec 10 17:26:39 2012 sergioandres baezserrano
*/

#include "my.h"

void    my_putnbr_base(int nb, char *base)
{
  int   base_len;

  base_len = my_strlen(base);
  if (nb == 0)
    return ;
  else
    {
      my_putnbr_base(nb / base_len, base);
      my_putchar(base[nb % base_len]);
    }
}
