/*
** my_fputstr.c for my_fputstr in /home/chapea_o//travail/rendu/lib/
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Wed Oct  3 13:26:43 2012 olivier chapeau
** Last update Wed Oct  3 13:38:58 2012 olivier chapeau
*/

#include <unistd.h>
#include "my.h"

int	my_fputstr(int fd, char *s)
{
  return (write(fd, s, my_strlen(s)));
}
