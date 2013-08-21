/*
** vm_game.c for src in /tmp/corewar-2016ed-2015s-2017si-baezse_s/vm/src
** 
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
** 
** Started on  Sat Dec 15 10:49:18 2012 sergioandres baezserrano
** Last update Sun Dec 16 18:01:29 2012 olivier chapeau
*/

#include "op.h"
#include "vm_help.h"
#include "vm_functions.h"

void	execute_command(t_processus *temp, unsigned char p_code)
{
}

int	execute_cycle(t_vm *vm, t_game *counters, int size_l)
{
  t_processus	*temp;
  int		i;
  unsigned char	p_code;

  i = 0;
  temp = get_processus_by_id(vm, counters->ids[counters->cycles % size_l]);
  p_code = vm->memory[temp->pc];
  while (i <= 16 && op_tab[i].code != p_code)
    i++;
  if (i > 16)
    temp->pc++;
  else
    {
      if (temp->nb_cycles == 0)
	execute_command(temp, p_code);
      else
	temp->nb_cycles--;
    }
  return (SUCCESS);
}

int	start_game(t_vm *vm)
{
  t_game	counters;
  int		size_l;

  size_l = size_list(vm->processes);
  if (size_l == 0)
    return (ENOPROCESS);
  counters.win = 0;
  counters.cycle_die = CYCLE_TO_DIE;
  if ((counters.ids = get_processes_ids(vm, size_l)) == NULL)
    return (EMALLOC);
  while (!counters.win)
    {
      counters.cycles = 0;
      counters.nbr_live = 0;
      while (counters.cycles < counters.cycle_die)
	{
	  execute_cycle(vm, &counters, size_l);
	  counters.cycles++;
	}
      counters.nbr_live++;
      if (counters.nbr_live == NBR_LIVE)
	counters.cycle_die -= CYCLE_DELTA;
    }
  return (SUCCESS);
}
