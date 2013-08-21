/*
** vm_help.h for include in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/include
** 
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
** 
** Started on  Fri Dec 14 19:04:42 2012 sergioandres baezserrano
<<<<<<< HEAD
** Last update Sun Dec 16 17:16:16 2012 olivier chapeau
=======
** Last update Sat Dec 15 18:41:46 2012 sergioandres baezserrano
>>>>>>> 760ff4b4c80b9b40f049593f39f43465bb0a70de
*/

#ifndef VM_HELP_H_
# define VM_HELP_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "op.h"
# include "my.h"
# include "vm.h"
# include "vm_files.h"
# include "vm_errors.h"
# include "vm_warriors.h"
# include "vm_processes.h"
# include "endianness.h"
# include "list.h"

typedef struct 	s_help
{
  unsigned char	*prog;
  int		prog_size;
  int		pc;
}		t_help;

typedef struct 	s_game
{
  int		cycle_die;
  int		cycles;
  int		win;
  int		nbr_live;
  int		*ids;
}	t_game;

#endif /* !VM_HELP_H_ */
