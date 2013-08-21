/*
** vm_destroy.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Dec 10 09:41:14 2012 olivier chapeau
** Last update Sat Dec 15 19:35:26 2012 sergioandres baezserrano
*/

#include <unistd.h>
#include <stdlib.h>
#include "vm.h"
#include "my.h"
#include "list.h"
#include "vm_files.h"
#include "vm_errors.h"
#include "vm_processes.h"

static int	close_files(t_list *files)
{
  int		i;
  int		size;
  t_link	*tmp;

  i = 0;
  size = size_list(files);
  tmp = files->first;
  while (i < size)
  {
    if (((t_file *)tmp->data)->fd != 0
        && close(((t_file *)tmp->data)->fd) == -1)
    {
      my_fputstr(STDERR, "Can't close '");
      my_fputstr(STDERR, ((t_file *)tmp->data)->name);
      return (ECLOSE);
    }
    i = i + 1;
    tmp = tmp->next;
  }
  return (SUCCESS);
}

void	free_registers(t_vm *vm)
{
  t_link	*temp;
  int		i;

  temp = vm->processes->first;
  while (temp != NULL)
    {
      i = 0;
      while (i < REG_NUMBER)
	{
	  free(((t_processus *)temp->data)->registers[i]);
	  i++;
	}
      free(((t_processus *)temp->data)->registers);
      temp = temp->next;
    }
}

int		destroy_vm(t_vm *vm, t_list **files)
{
  int		ret;

  apply_in_list(vm->warriors, &free);
  clear_list(&vm->warriors);
  free_registers(vm);
  apply_in_list(vm->processes, &free);
  clear_list(&vm->processes);
  if ((ret = close_files(*files)) != SUCCESS)
    return (ret);
  apply_in_list(*files, &free);
  clear_list(files);
  return (SUCCESS);
}
