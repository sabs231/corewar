/*
** main.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Dec 03 10:39:17 2012 olivier chapeau
** Last update Sun Dec 16 17:00:39 2012 olivier chapeau
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"
#include "op.h"
#include "vm_errors.h"
#include "vm_options.h"
#include "vm_instructions.h"
#include "vm_functions.h"
#include "vm_files.h"
#include "vm_warriors.h"
#include "vm_processes.h"

void	display_warrior(void *elt)
{
  my_putstr("---------\n");
  my_putstr(" WARRIOR\n");
  my_putstr("---------\nid\t: ");
  my_put_nbr(((t_warrior *)elt)->id);
  my_putstr("\n---------\n");
}

void	display_processus(void *elt)
{
  my_putstr("---------\n");
  my_putstr(" PROCESS\n");
  my_putstr("---------\nid\t: ");
  my_put_nbr(((t_processus *)elt)->id);
  my_putstr("\npc\t: ");
  my_put_nbr(((t_processus *)elt)->pc);
  my_putstr("\n---------\n");
}

void	display_files(void *elt)
{
  my_putstr("---------\n");
   my_putstr("  FILE\n");
  my_putstr("---------\nfile name\t: ");
  my_putstr(((t_file *)elt)->name);
  my_putstr("\n---------\n");
}

void	display_dump(t_vm *vm)
{
  my_putstr("dump ? ");
  my_put_nbr(vm->options_flags << DUMP);
  my_putstr("\tdump_cycles : ");
  my_put_nbr(vm->dump_cycles);
  my_putstr("\n");
}

int		main(int argc, char **argv)
{
  int		ret;
  t_vm		vm;
  t_list	*files;

  files = NULL;
  if ((ret = init_vm_and_get_options(argc, argv, &vm, &files)) != SUCCESS)
    return (ret);
  if ((ret = check_prepare_vm(argv, &vm, &files)) != SUCCESS)
    return (ret);
  display_dump(&vm);
  apply_in_list(vm.warriors, &display_warrior);
  apply_in_list(vm.processes, &display_processus);
  apply_in_list(files, &display_files);
  dump_memory(&vm);
  if ((ret = destroy_vm(&vm, &files)) != SUCCESS)
  {
    vm_display_errors(ret, argv[0]);
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
