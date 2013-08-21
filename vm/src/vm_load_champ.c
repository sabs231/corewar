/*
** vm_load_champ.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
** 
** Started on  Thu Dec 13 19:08:41 2012 sergioandres baezserrano
** Last update Sun Dec 16 15:27:14 2012 olivier chapeau
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "my.h"
#include "vm.h"
#include "vm_files.h"
#include "vm_errors.h"
#include "vm_warriors.h"
#include "vm_processes.h"
#include "endianness.h"
#include "vm_functions.h"
#include "list.h"
#include "vm_help.h"

int	check_memory_space(t_vm *vm, int low, int high)
{
  while (low <= high)
  {
    if (vm->memory[low % MEM_SIZE] != '\0')
      return (1);
    low++;
  }
  return (0);
}

int	check_vm_champs(t_vm *vm, t_processus *temp_p, t_link *temp_w)
{
  int		low;
  int		high;

  low = temp_p->pc;
  high = ((t_warrior *)temp_w->data)->header.prog_size + low;
  if (check_memory_space(vm, low, high))
    return (0);
  return (1);
}

int	return_size_error(int prog_size, t_link *temp_f)
{
  my_fputstr(STDERR, ((t_file *)temp_f->data)->name);
  my_fputstr(STDERR, " size : ");
  my_fputnbr(STDERR, prog_size);
  return (ESIZE);
}

int	check_and_fill_vm(t_vm *vm, t_help *help, t_processus *temp_p,
                          t_link *temp_w)
{
  if (temp_p->pc != 0)
  {
    if (check_vm_champs(vm, temp_p, temp_w))
      my_strncpy(vm, help->prog, help->prog_size, temp_p->pc % MEM_SIZE);
    else
      return (EOVERLAP);
  }
  else
  {
    temp_p->pc = help->pc;
    if (check_vm_champs(vm, temp_p, temp_w))
      my_strncpy(vm, help->prog, help->prog_size, temp_p->pc % MEM_SIZE);
    else
      return (EOVERLAP);
  }
  free(help->prog);
  return (SUCCESS);
}

int			fill_vm(t_link *temp_w, t_link *temp_f, t_vm *vm, int pc)
{
  int				n_war;
  t_processus			*temp_p;
  t_help			help;

  n_war = size_list(vm->warriors);
  help.prog_size = ((t_warrior *)temp_w->data)->header.prog_size;
  if ((MEM_SIZE / n_war) < help.prog_size)
    return (return_size_error(help.prog_size, temp_f));
  if ((help.prog = malloc(((t_warrior *)temp_w->data)->header.prog_size))
                 == NULL)
    return (EMALLOC);
  if (read(((t_file *)temp_f->data)->fd, help.prog, help.prog_size) <= 0)
    return (EREAD);
  if ((temp_p = get_processus_by_id(vm, ((t_warrior *)temp_w->data)->id))
              == NULL)
    return (EID_PROCESS);
  help.pc = pc;
  if (check_and_fill_vm(vm, &help, temp_p, temp_w) != SUCCESS)
    return (EOVERLAP);
  return (SUCCESS);
}
