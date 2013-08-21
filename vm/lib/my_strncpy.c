/*
** my_strncpy.c for lib in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/lib
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Oct  8 10:18:55 2012 olivier chapeau
** Last update Sun Dec 16 15:24:57 2012 olivier chapeau
*/

#include "op.h"
#include "vm.h"

void	my_strncpy(t_vm *vm, unsigned char *src, int n, int pc)
{
  int	i;
  int	j;

  i = pc;
  j = 0;
  while (i < (pc + n))
    {
      vm->memory[i % MEM_SIZE] = src[j];
      i = i + 1;
      j = j + 1;
    }
}
