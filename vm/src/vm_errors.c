/*
** vm_errors.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Tue Dec 04 16:03:59 2012 olivier chapeau
** Last update Sat Dec 15 12:01:44 2012 sergioandres baezserrano
*/

#include "my.h"
#include "vm_errors.h"
#include "vm_bool.h"

t_errors	g_vm_errors[] =
{
  {EOPEN, "': No such file or directory.\n"},
  {ECLOSE, "'.\n"},
  {EREAD, "Can't perform read.\n"},
  {EMALLOC, "Can't perform malloc.\n"},
  {ETMCHAMPIONS, "Too many Champions : The maximum is 4.\n"},
  {ENOT_COR_EXE, " is not a corewar executable.\n"},
  {E_ID_USED, " is already used.\n"},
  {ESIZE, " is TOO BIG\n"},
  {EID_PROCESS, "The id of the process does not exists\n"},
  {EOVERLAP, "The programs ovelap, choose a different address\n"},
  {ENOPROCESS, "There are no processes\n"}
} ;

static void	display_usage(char *name)
{
  my_fputstr(STDERR, "Usage: ");
  my_fputstr(STDERR, name);
  my_fputstr(STDERR, " [-dump nbr_cycle] ");
  my_fputstr(STDERR, "[[-n prog_number] [-a load_adress] prog_name]\n");
}

void		vm_display_errors(int err_num, char *string)
{
  unsigned char	i;
  vm_bool	found;

  i = 0;
  found = FALSE;
  if (err_num == EUSAGE)
    display_usage(string);
  else
  {
    while (i < VM_NB_ERRORS && found == FALSE)
    {
      if (i + 1 == err_num)
      {
        my_fputstr(STDERR, g_vm_errors[i].msg);
        found = TRUE;
      }
      i = i + 1;
    }
  }
}
