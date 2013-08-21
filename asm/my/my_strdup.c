/*
** my_strdup.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Wed Oct 10 09:20:06 2012 julien regnier
** Last update Mon Dec 03 11:50:30 2012 julien regnier
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*res;

  if ((res = malloc(my_strlen(src) + 1)) == NULL)
    return NULL;
  my_strncpy(res, src, my_strlen(src));
  *(res + my_strlen(src)) = 0;
  return (res);
}
