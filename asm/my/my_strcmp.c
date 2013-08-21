/*
** my_strcmp.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Oct  8 12:23:40 2012 julien regnier
** Last update Fri Dec 14 11:07:58 2012 julien regnier
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == 0 || s2 == 0)
    return (-1);
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	{
	  return (s1[i] - s2[i]);
	}
      i = i + 1;
    }
  if (s1[i] == '\0')
    return (s1[i] - s2[i]);
  if (s2[i] == '\0')
    return (s1[i]);
  return (0);
}
