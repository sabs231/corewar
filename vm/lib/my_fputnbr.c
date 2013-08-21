/*
** my_fputnbr.c for lib in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/lib
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Wed Oct  3 18:58:15 2012 olivier chapeau
** Last update Tue Dec 11 18:22:44 2012 olivier chapeau
*/

#include "my.h"

void		my_fputnbr_aux(int fd, unsigned int nb)
{
  unsigned int	mod;
  char		c;

  mod = nb % 10;
  c = '0';
  while (mod != 0)
    {
      mod = mod - 1;
      c = c + 1;
    }
  if (nb / 10 != 0)
    my_fputnbr_aux(fd, nb / 10);
  my_fputchar(fd, c);
}

void		my_fputnbr(int fd, int nb)
{
  unsigned int	new_nb;

  if (nb < 0)
    {
      my_fputchar(fd, '-');
      nb = nb * -1;
    }
  if (nb == 0)
    {
      my_fputchar(fd, '0');
      return ;
    }
  new_nb = nb;
  my_fputnbr_aux(fd, new_nb);
}
