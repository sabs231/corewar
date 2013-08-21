/*
** compressor.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/src
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun Dec 09 18:35:09 2012 Marin Alcaraz
** Last update Sat Dec 15 17:21:20 2012 olivier chapeau
*/

#include <stdlib.h>
#include "my.h"
#include "instruction.h"
#include "label.h"

char	*paste(char *new, char *src, char glue, int *index)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
  {
    new[*index] = src[i];
    *index = *index + 1;
    i = i + 1;
  }
  new[*index] = glue;
  *index = *index + 1;
  return (new);
}

char	*append(char *s1, char *s2, char glue)
{
  char 	*new;
  int	total;
  int	index;

  index = 0;
  total = my_strlen(s1) + my_strlen(s2);
  if ((new = malloc(total + 2)) == NULL)
    return (NULL);
  paste(new, s1, glue, &index);
  paste(new, s2, '\0', &index);
  return (new);
}

int     compressor(char ***tab)
{
  int i;

  i = 0;
  while ((*tab)[i])
  {
    if (my_strcmp(((*tab)[i]), "+") == 0
        || my_strcmp(((*tab)[i]), "-") == 0)
    {
      if (((*tab)[i - 1] = append((*tab)[i - 1],
              (*tab)[i + 1], (*tab)[i][0])) == NULL)
        return (1);
      (*tab)[i][0] = '\0';
      (*tab)[i + 1][0] = '\0';
    }
    i = i + 1;
  }
  return (0);
}
