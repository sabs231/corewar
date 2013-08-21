/*
** vm_functions.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
** 
** Started on  Sun Dec  9 13:33:54 2012 sergioandres baezserrano
** Last update Sat Dec 15 18:33:16 2012 sergioandres baezserrano
*/

#include <stdlib.h>
#include "vm.h"
#include "../my.h"
#include "vm_functions.h"
#include "op.h"

void	print_memory(t_vm *vm, int i, int j)
{
  if (vm->memory[i] == 0)
    {
      my_putchar('0');
      my_putchar('0');
    }
  else if (vm->memory[i] < 10)
    my_put_nbr(vm->memory[i]);
  else
    {
      if (vm->memory[i] < 16)
	my_putchar('0');
      my_putnbr_base(vm->memory[i], "0123456789abcdef");
    }
  if (j % 16 == 0)
    my_putchar('\n');
  else
    my_putchar(' ');
}

void	print_address(int i)
{
  if (i % 16 == 0)
    {
      if (i == 0)
	my_putstr("00");
      if (i < 256)
	my_putstr("00");
      if (i < 4096 && i >= 256)
	my_putchar('0');
      my_putnbr_base(i, "0123456789abcdef");
      my_fputstr(1, " : ");
    }
}

void	dump_memory(t_vm *vm)
{
  int	i;
  int	j;

  i = 0;
  j = 1;
  while (i < MEM_SIZE)
    {
      print_address(i);
      print_memory(vm, i, j);
      j++;
      i++;
    }
}

void	init_registers(t_processus *temp)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < REG_NUMBER)
    {
      while (j < REG_SIZE)
	{
	  temp->registers[i][j] = '\0';
	  j++;
	}
      i++;
      j = 0;
    }
}

int	*get_processes_ids(t_vm *vm, int size_l)
{
  t_link	*temp;
  int		i;
  int		*ids;

  i = 0;
  temp = vm->processes->first;
  if ((ids = malloc(size_l)) == NULL)
    return (NULL);
  while (temp != NULL)
    {
      ids[i] = ((t_processus *)temp->data)->id;
      init_registers((t_processus *)temp->data);
      ((t_processus *)temp->data)->registers[0] = (unsigned char *)&ids[i];
      ((t_processus *)temp->data)->nb_cycles = 0;
      temp = temp->next;
      i++;
    }
  return (ids);
}
