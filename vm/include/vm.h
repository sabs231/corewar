/*
** vm.h for include in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/include
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Thu Dec 06 19:09:56 2012 olivier chapeau
** Last update Sun Dec 16 16:47:07 2012 olivier chapeau
*/

#ifndef VM_H_
# define VM_H_

# include "op.h"
# include "list.h"

struct		s_vm
{
  unsigned char	memory[MEM_SIZE];
  unsigned int	dump_cycles;
  int	        options_flags;
  t_list	*warriors;
  t_list	*processes;
} ;

typedef struct s_vm t_vm;

int	init_vm(t_vm *vm, t_list **files);
int	prepare_vm(t_list *files, t_vm *vm);
int	init_vm_and_get_options(int argc, char **argv, t_vm *vm, t_list **files);
int	check_prepare_vm(char **argv, t_vm *vm, t_list **files);
int	destroy_vm(t_vm *vm, t_list **files);

#endif /* !VM_H_ */
