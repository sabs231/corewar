/*
** vm_processes.h for include in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/include
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Thu Dec 06 19:34:18 2012 olivier chapeau
<<<<<<< HEAD
** Last update Sun Dec 16 17:16:37 2012 olivier chapeau
=======
** Last update Sat Dec 15 19:04:58 2012 sergioandres baezserrano
>>>>>>> 760ff4b4c80b9b40f049593f39f43465bb0a70de
*/

#ifndef VM_PROCESSES_H_
# define VM_PROCESSES_H_

# include "op.h"
# include "vm_bool.h"
# include "vm.h"

struct		s_processus
{
  unsigned int	id;
  unsigned char	**registers;
  unsigned int	pc;
  vm_bool	carry;
  unsigned int	nb_cycles;
} ;

typedef struct s_processus t_processus;

t_processus	*new_processus(void);
t_processus	*get_processus_by_id(t_vm *vm, unsigned int id);

#endif /* !VM_PROCESSES_H_ */
