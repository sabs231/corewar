/*
** my_strcpy.c for lib in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/lib
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Oct  8 09:31:32 2012 olivier chapeau
** Last update Wed Dec 12 18:03:33 2012 olivier chapeau
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
