/*
** vm_calc_instructions.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Tue Dec 11 15:57:52 2012 olivier chapeau
** Last update Sun Dec 16 15:29:06 2012 olivier chapeau
*/

#include "vm.h"
#include "vm_processes.h"

void		add(t_vm *vm, int id)
{
  unsigned char	encoding_byte;
  char		params[3];
  t_processus	*processus;

  if ((processus = get_processus_by_id(vm, id)) == NULL)
    return ;
  encoding_byte = vm->memory[++processus->pc];
  if ((encoding_byte & PARAM1) != 0x40
      || (encoding_byte & PARAM2) != 0x10
      || (encoding_byte & PARAM3) != 0x04)
  {
    processus->carry = 0;
    return ;
  }
  params[0] = processus->registers[vm->memory[++processus->pc]];
  params[1] = processus->registers[vm->memory[++processus->pc]];
  params[2] = vm->memory[++processus->pc];
  processus->registers[params[2]] = params[0] + params[1];
  processus->carry = 1;
}

void		sub(t_vm *vm, int id)
{
  unsigned char	encoding_byte;
  char		params[3];
  t_processus	*processus;

  if ((processus = get_processus_by_id(vm, id)) == NULL)
    return ;
  encoding_byte = vm->memory[++processus->pc];
  if ((encoding_byte & PARAM1) != 0x40
      || (encoding_byte & PARAM2) != 0x10
      || (encoding_byte & PARAM3) != 0x04)
  {
    processus->carry = 0;
    return ;
  }
  params[0] = processus->registers[vm->memory[++processus->pc]];
  params[1] = processus->registers[vm->memory[++processus->pc]];
  params[2] = vm->memory[++processus->pc];
  processus->registers[params[2]] = params[0] - params[1];
  processus->carry = 1;
}
