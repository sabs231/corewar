/*
** vm_processes.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Dec 10 14:02:11 2012 olivier chapeau
** Last update Sat Dec 15 19:36:03 2012 sergioandres baezserrano
*/

#include <stdlib.h>
#include "op.h"
#include "vm_processes.h"
#include "vm_bool.h"
#include "vm.h"
#include "list.h"
#include "vm_errors.h"

static int	init_registers(t_processus *processus)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((processus->registers = malloc(sizeof(char *) * REG_NUMBER)) == NULL)
    return (EMALLOC);
  while (i < REG_NUMBER)
  {
    if ((processus->registers[i] = malloc(REG_SIZE)) == NULL)
      return (EMALLOC);
    while (j < REG_SIZE)
    {
      processus->registers[i][j] = '\0';
      j = j + 1;
    }
    i = i + 1;
    j = 0;
  }
  return (SUCCESS);
}

t_processus	*new_processus(void)
{
  t_processus	*processus;

  if ((processus = malloc(sizeof(t_processus))) == NULL)
    return (NULL);
  processus->id = 0;
  processus->pc = 0;
  processus->carry = 0;
  processus->nb_cycles = 0;
  if (init_registers(processus) != SUCCESS)
    return (NULL);
  return (processus);
}

t_processus	*get_processus_by_id(t_vm *vm, unsigned int id)
{
  t_link	*tmp;

  tmp = vm->processes->first;
  if (tmp->next == NULL && ((t_processus *)tmp->data)->id == id)
      return ((t_processus *)tmp->data);
  while (tmp != NULL)
  {
    if (((t_processus *)tmp->data)->id == id)
      return ((t_processus *)tmp->data);
    tmp = tmp->next;
  }
  return (NULL);
}
