/*
** vm_options.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Wed Dec 05 18:31:52 2012 olivier chapeau
** Last update Sun Dec 16 16:09:29 2012 olivier chapeau
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"
#include "vm_options.h"
#include "vm_bool.h"
#include "vm_errors.h"
#include "vm_files.h"
#include "vm_warriors.h"
#include "vm_processes.h"

static t_options	g_vm_options[] =
{
  {"-dump", &get_dump},
  {"-n", &get_warrior_id},
  {"-a", &get_warrior_address}
} ;

vm_bool		g_new_warrior;
int		g_warrior_id;

int		insert_warrior_in_vm(t_vm *vm, int id, int pc)
{
  t_warrior	*warrior;
  t_processus	*processus;

  if ((warrior = new_warrior()) == NULL)
    return (EMALLOC);
  warrior->id = id;
  insert_in_list(vm->warriors, warrior);
  if ((processus = new_processus()) == NULL)
    return (EMALLOC);
  processus->id = id;
  processus->pc = pc;
  insert_in_list(vm->processes, processus);
  return (SUCCESS);
}

int		insert_file_in_vm(t_vm *vm, t_list *files, char *name)
{
  int		ret;
  t_file	*tmp;

  if (g_new_warrior == TRUE)
  {
    if ((ret = insert_warrior_in_vm(vm, g_warrior_id, 0)) != SUCCESS)
      return (ret);
    g_warrior_id = g_warrior_id + 1;
  }
  if (size_list(files) == 4)
    return (ETMCHAMPIONS);
  if ((tmp = new_file()) == NULL)
    return (EMALLOC);
  tmp->name = name;
  insert_in_list(files, tmp);
  g_new_warrior = TRUE;
  return (SUCCESS);
}

static int	check_is_option(t_vm *vm, char **argv, int *i, vm_bool *found)
{
  int		j;
  int		ret;

  j = 0;
  *found = FALSE;
  while (j < VM_NB_OPTIONS && *found == FALSE)
  {
    if (!my_strcmp(argv[*i], g_vm_options[j].option))
    {
      *found = TRUE;
      if ((ret = (*g_vm_options[j].f)(argv, vm, i)) != SUCCESS)
        return (ret);
    }
    j = j + 1;
  }
  return (SUCCESS);
}

int		get_options(int argc, char **argv, t_vm *vm, t_list *files)
{
  int		i;
  int		ret;
  vm_bool	found;

  i = 1;
  found = FALSE;
  ret = SUCCESS;
  g_new_warrior = TRUE;
  g_warrior_id = 0;
  if (argc <= 1)
    return (EUSAGE);
  while (i < argc)
  {
    if ((ret = check_is_option(vm, argv, &i, &found)) != SUCCESS)
      return (ret);
    if (found == FALSE)
    {
      if ((ret = insert_file_in_vm(vm, files, argv[i])) != SUCCESS)
        return (ret);
    }
    i = i + 1;
  }
  if (is_empty_list(files))
    return (EUSAGE);
  return (ret);
}
