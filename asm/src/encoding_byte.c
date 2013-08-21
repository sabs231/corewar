/*
** encoding_byte.c for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Thu Dec 13 20:11:21 2012 julien regnier
** Last update Thu Dec 13 20:35:27 2012 julien regnier
*/

#include "my.h"
#include "op.h"

void	get_encoding_byte(char **my_tab, int *encoding_byte)
{
  int	i;
  int	j;

  i = 0;
  j = 6;
  while (my_tab && my_tab[i])
  {
    if (my_tab[i][0] == 'r')
      *encoding_byte |= (1 << j);
    else if (my_tab[i][0] == DIRECT_CHAR)
      *encoding_byte |= (2 << j);
    else
      *encoding_byte |= (3 << j);
    j = j - 2;
    i = i + 1;
  }
}
