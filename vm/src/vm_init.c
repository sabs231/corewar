/*
** vm_init.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Fri Dec 07 17:28:10 2012 olivier chapeau
** Last update Sun Dec 16 16:50:16 2012 olivier chapeau
*/

#include "op.h"
#include "vm.h"
#include "list.h"
#include "vm_errors.h"
#include "vm_functions.h"
#include "vm_options.h"

static void	init_memory(unsigned char memory[], int size)
{
  int		i;

  i = 0;
  while (i < size)
  {
    memory[i] = 0;
    i = i + 1;
  }
}

int	init_vm(t_vm *vm, t_list **files)
{
  if ((vm->warriors = new_list()) == NULL)
    return (EMALLOC);
  if ((vm->processes = new_list()) == NULL)
    return (EMALLOC);
  init_memory(vm->memory, MEM_SIZE);
  vm->dump_cycles = 0;
  vm->options_flags = 0;
  if ((*files = new_list()) == NULL)
    return (EMALLOC);
  return (SUCCESS);
}

int	prepare_vm(t_list *files, t_vm *vm)
{
  int	ret;

  if (open_files(files) == EOPEN)
    return (EOPEN);
  if ((ret = read_header(files, vm)) != SUCCESS)
    return (ret);
  if ((ret = read_program(files, vm)) != SUCCESS)
    return (ret);
  return (SUCCESS);
}

int	init_vm_and_get_options(int argc, char **argv, t_vm *vm, t_list **files)
{
  int	ret;

  if ((ret = init_vm(vm, files)) != SUCCESS)
  {
    vm_display_errors(ret, argv[0]);
    return (EXIT_FAILURE);
  }
  if ((ret = get_options(argc, argv, vm, *files)) != SUCCESS)
  {
    vm_display_errors(ret, argv[0]);
    if ((ret = destroy_vm(vm, files)) != SUCCESS)
    {
      vm_display_errors(ret, argv[0]);
      return (EXIT_FAILURE);
    }
    return (EXIT_FAILURE);
  }
  return (SUCCESS);
}

int	check_prepare_vm(char **argv, t_vm *vm, t_list **files)
{
  int	ret;

  if ((ret = prepare_vm(*files, vm)) != SUCCESS)
  {
    vm_display_errors(ret, argv[0]);
    if ((ret = destroy_vm(vm, files)) != SUCCESS)
    {
      vm_display_errors(ret, argv[0]);
      return (EXIT_FAILURE);
    }
    return (EXIT_FAILURE);
  }
  return (SUCCESS);
}
