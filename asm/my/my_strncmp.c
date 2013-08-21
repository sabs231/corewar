/*
** my_strncmp.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Oct  8 12:23:40 2012 julien regnier
** Last update Fri Dec 14 10:46:48 2012 julien regnier
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	len;
  int	len2;

  len = my_strlen(s1);
  len2 = my_strlen(s2);
  if (n == 0)
    return (0);
  if (n < 0)
    n = (len > len2) ? len : len2;
  i = 0;
  while (i < n)
    {
      if (s1 && s2 && s1[i] != s2[i])
	  return (s1[i] - s2[i]);
      if (s1 && s2 && s1[i] == '\0')
	  return (s1[i] - s2[i]);
      if (s1 && s2 && s2[i] == '\0')
	  return (s1[i]);
      i = i + 1;
    }
  return (0);
}
