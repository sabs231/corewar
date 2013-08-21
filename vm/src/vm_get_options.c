/*
** vm_get_options.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Dec 10 16:08:54 2012 olivier chapeau
** Last update Sun Dec 16 16:32:00 2012 olivier chapeau
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"
#include "vm_options.h"
#include "vm_bool.h"
#include "vm_errors.h"
#include "vm_files.h"
#include "vm_processes.h"
#include "vm_warriors.h"

extern vm_bool	g_new_warrior;
extern int	g_warrior_id;

int	get_dump(char **argv, t_vm *vm, int *i)
{
  int	dump_cycles;

  *i = *i + 1;
  if (vm->options_flags << DUMP)
    return (EUSAGE);
  if (argv[*i] == NULL)
    return (EUSAGE);
  if ((dump_cycles = my_get_unsigned_nbr(argv[*i])) == -1)
    return (EUSAGE);
  vm->options_flags |= (1 << DUMP);
  vm->dump_cycles = dump_cycles;
  return (SUCCESS);
}

static int	check_id(t_list *warriors, unsigned int id)
{
  int		i;
  int		size;
  t_link	*tmp;

  i = 0;
  size = size_list(warriors);
  tmp = warriors->first;
  while (i < size)
  {
    if (((t_warrior *)tmp->data)->id == id)
    {
      my_fputstr(STDERR, "Prog number ");
      my_fputnbr(STDERR, id);
      return (E_ID_USED);
    }
    i = i + 1;
    tmp = tmp->next;
  }
  return (SUCCESS);
}

int	get_warrior_id(char **argv, t_vm *vm, int *i)
{
  int	id;
  int	ret;

  *i = *i + 1;
  if (argv[*i] == NULL)
    return (EUSAGE);
  if ((id = my_get_unsigned_nbr(argv[*i])) == -1)
    return (EUSAGE);
  if ((ret = check_id(vm->warriors, id)) != SUCCESS)
    return (ret);
  if (g_new_warrior == TRUE)
  {
    if ((ret = insert_warrior_in_vm(vm, id, 0)) != SUCCESS)
      return (ret);
    g_new_warrior = FALSE;
    g_warrior_id = g_warrior_id + 1;
  }
  else
    return (EUSAGE);
  return (SUCCESS);
}

int	get_warrior_address(char **argv, t_vm *vm, int *i)
{
  int	address;
  int	ret;

  *i = *i + 1;
  if (argv[*i] == NULL)
    return (EUSAGE);
  if ((address = my_get_unsigned_nbr(argv[*i])) == -1)
    return (EUSAGE);
  if (g_new_warrior == TRUE)
  {
    if ((ret = insert_warrior_in_vm(vm, g_warrior_id, address)) != SUCCESS)
      return (ret);
    g_new_warrior = FALSE;
    g_warrior_id = g_warrior_id + 1;
  }
  else
  {
    if (((t_processus *)get_last_link(vm->processes)->data)->pc != 0)
      return (EUSAGE);
    ((t_processus *)get_last_link(vm->processes)->data)->pc = address;
  }
  return (SUCCESS);
}
