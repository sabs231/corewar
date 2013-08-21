/*
** vm_files.c for include in /home/chapea_o/travail/corewar/src/include
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Dec 10 15:03:47 2012 olivier chapeau
** Last update Mon Dec 10 15:09:25 2012 olivier chapeau
*/

#include <stdlib.h>
#include "vm_files.h"

t_file      *new_file(void)
{
  t_file    *file;

  if ((file = malloc(sizeof(t_file))) == NULL)
    return (NULL);
  file->name = "";
  file->fd = 0;
  return (file);
}
