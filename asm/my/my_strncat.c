/*
** my_strncat.c for my_strncat in /home/regnie_j//afs/Jour_07/ex_01
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Tue Oct  9 15:46:59 2012 julien regnier
** Last update Tue Oct  9 15:49:07 2012 julien regnier
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	dest_len;

  dest_len = 0;
  while (dest[dest_len])
    dest_len = dest_len + 1;
  i = 0;
  while (src[i] != '\0' && i < nb)
    {
      dest[dest_len + i] = src[i];
      i = i + 1;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
