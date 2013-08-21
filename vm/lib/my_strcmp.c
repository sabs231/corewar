/*
** my_strcmp.c for my_strcmp in /home/chapea_o//travail/rendu/lib/
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Oct  8 15:18:15 2012 olivier chapeau
** Last update Tue Oct 23 14:31:01 2012 olivier chapeau
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  if (s1[i] == '\0')
    return (s1[i] - s2[i]);
  if (s2[i] == '\0')
    return (s1[i]);
  return (0);
}
