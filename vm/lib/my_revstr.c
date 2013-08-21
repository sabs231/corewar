/*
** my_revstr.c for my_revstr in /home/chapea_o/travail/rendu/lib
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Oct  8 10:27:59 2012 olivier chapeau
** Last update Mon Oct  8 17:06:51 2012 olivier chapeau
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	mi;
  int	len;
  char	tmp;

  len = my_strlen(str);
  i = 0;
  mi = len / 2;
  while (mi > 0)
    {
      tmp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = tmp;
      mi = mi - 1;
      i = i + 1;
    }
  return (str);
}
