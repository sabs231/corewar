/*
** my_strncmp.c for my_strncmp in /home/chapea_o//travail/rendu/lib/
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Oct  8 15:18:15 2012 olivier chapeau
** Last update Mon Oct  8 17:57:49 2012 olivier chapeau
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	len_s1;
  int	len_s2;

  len_s1 = my_strlen(s1);
  len_s2 = my_strlen(s2);
  if (n < 0)
    n = (len_s1 > len_s2 ? len_s1 : len_s2);
  i = 0;
  while (i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      if (s1[i] == '\0')
	return (s1[i] - s2[i]);
      if (s2[i] == '\0')
	return (s2[i]);
      i = i + 1;
    }
  return (0);
}
