/*
** vm_warriors.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Fri Dec 07 17:41:34 2012 olivier chapeau
** Last update Wed Dec 12 14:33:25 2012 sergioandres baezserrano
*/

#include <stdlib.h>
#include "vm_warriors.h"
#include "vm_bool.h"
#include "list.h"
#include "vm.h"
#include "op.h"
#include "endianness.h"

t_warrior      *new_warrior(void)
{
  t_warrior    *warrior;

  if ((warrior = malloc(sizeof(t_warrior))) == NULL)
    return (NULL);
  warrior->id = 0;
  warrior->is_alive = TRUE;
  return (warrior);
}

void		insert_header(t_warrior *warrior, header_t *header)
{
  if (warrior != NULL && header != NULL)
  {
    warrior->header = *header;
    swap_bytes((char *)&warrior->header.magic, sizeof(header->magic));
    swap_bytes((char *)&warrior->header.prog_size, sizeof(header->prog_size));
  }
}

t_warrior	*get_warrior_by_id(t_vm *vm, unsigned int id)
{
  t_link	*tmp;

  tmp = vm->warriors->first;
  if (tmp->next == NULL)
      return ((t_warrior *)tmp->data);
  while (tmp->next != NULL)
  {
    if (((t_warrior *)tmp->data)->id == id)
      return ((t_warrior *)tmp->data);
    tmp = tmp->next;
  }
  return (NULL);
}
