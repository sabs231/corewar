/*
** my_strncpy.c for my_strncpy in /home/regnie_j//afs/Jour_06
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Sun Oct  7 11:53:03 2012 julien regnier
** Last update Tue Oct  9 09:37:35 2012 julien regnier
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  while (i < n)
    {
      dest[i] = '\0';
      i = i + 1;
    }
  return (dest);
}
