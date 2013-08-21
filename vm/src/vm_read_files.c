/*
** vm_read_files.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
** 
** Started on  Fri Dec  7 17:30:46 2012 sergioandres baezserrano
** Last update Fri Dec 14 16:47:12 2012 sergioandres baezserrano
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

int		open_files(t_list *files)
{
  t_link	*temp;
  int		fd;

  temp = files->first;
  while (temp != NULL)
  {
    if ((fd = open(((t_file *)temp->data)->name, O_RDONLY)) == -1)
    {
      my_fputstr(STDERR, "Can't open '");
      my_fputstr(STDERR, ((t_file *)temp->data)->name);
      return (EOPEN);
    }
    ((t_file *)temp->data)->fd = fd;
    temp = temp->next;
  }
  return (SUCCESS);
}

int		read_header(t_list *files, t_vm *vm)
{
  t_link	*temp_f;
  t_link	*temp_w;
  header_t	header;

  temp_f = files->first;
  temp_w = vm->warriors->first;
  while (temp_f != NULL && temp_w != NULL)
  {
    if (read(((t_file *)temp_f->data)->fd, &header, sizeof(header_t)) <= 0)
      return (EREAD);
    insert_header((t_warrior *)temp_w->data, &header);
    if (((t_warrior *)temp_w->data)->header.magic != COREWAR_EXEC_MAGIC)
    {
      my_fputstr(STDERR, ((t_file *)temp_f->data)->name);
      return (ENOT_COR_EXE);
    }
    temp_f = temp_f->next;
    temp_w = temp_w->next;
  }
  return (SUCCESS);
}

int			read_program(t_list *files, t_vm *vm)
{
  int			error;
  int			index;
  int			pc;
  t_link		*temp_f;
  t_link		*temp_w;

  index = size_list(vm->warriors) - 1;
  temp_f = files->first;
  temp_w = vm->warriors->first;
  while (temp_f != NULL)
  {
    pc = index * (MEM_SIZE / size_list(vm->warriors));
    if ((error = fill_vm(temp_w, temp_f, vm, pc)) != SUCCESS)
      return (error);
    index--;
      temp_w = temp_w->next;
      temp_f = temp_f->next;
  }
  return (SUCCESS);
}
