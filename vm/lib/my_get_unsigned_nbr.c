/*
** my_get_unsigned_nbr.c for lib in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/lib
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Thu Oct  4 10:56:02 2012 olivier chapeau
** Last update Mon Dec 10 20:18:16 2012 olivier chapeau
*/

#include "my.h"

int		my_get_unsigned_nbr(char *str)
{
  int		i;
  unsigned int	nb;

  i = 0;
  nb = 0;
  while (str[i] == '+')
      i = i + 1;
  if (!(str[i] >= '0' && str[i] <= '9'))
    return (-1);
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + (str[i] - '0');
      i = i + 1;
    }
  return (nb);
}
