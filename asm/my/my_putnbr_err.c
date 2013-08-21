/*
** my_putnbr_err.c for my in /home/regnie_j/corewar/my
**
** Made by julien regnier
** Login   <regnie_j@epitech.net>
**
** Started on  Wed Oct  3 15:58:24 2012 julien regnier
** Last update Mon Dec 03 15:19:58 2012 julien regnier
*/

#include <unistd.h>
#include "my.h"

void	my_putnbr_recu(unsigned int nb, int fd)
{
  int	mod;
  char	c;

  mod = nb % 10;
  c = '0';
  while (mod != 0)
    {
      c = c + 1;
      mod = mod - 1;
    }
  if (nb / 10 != 0)
    my_putnbr_recu(nb / 10, fd);
  write(fd, &c, 1);
}

void		my_putnbr_err(int nb, int fd)
{
  unsigned int	new_nb;
  char		tmp;

  if (nb == 0)
    {
      tmp = '0';
      write(fd, &tmp, 1);
      return ;
    }
  if (nb < 0)
    {
      tmp = '-';
      write(fd, &tmp, 1);
      nb = nb * -1;
    }
  new_nb = nb;
  my_putnbr_recu(new_nb, fd);
}
