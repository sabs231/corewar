/*
** vm_functions.h for include in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/include
** 
** Made by sergioandres baezserrano
** Login   <baezse_s@epitech.net>
** 
** Started on  Thu Dec 06 20:41:15 2012 sergioandres baezserrano
<<<<<<< HEAD
** Last update Sun Dec 16 17:15:41 2012 olivier chapeau
=======
** Last update Sat Dec 15 18:42:47 2012 sergioandres baezserrano
>>>>>>> 760ff4b4c80b9b40f049593f39f43465bb0a70de
*/

#ifndef VM_FUNCTIONS_H_
#  define VM_FUNCTIONS_H_

#  include <sys/types.h>
#  include "op.h"
#  include "list.h"
#  include "vm_processes.h"
#  include "vm_help.h"

int	read_header(t_list *files, t_vm *vm);
int	open_files(t_list *files);
int	read_program(t_list *files, t_vm *vm);
void	print_memory(t_vm *vm, int i, int j);
void	print_address(int i);
void	dump_memory(t_vm *vm);
int	return_size_error(int prog_size, t_link *temp_f);
int	fill_vm(t_link *temp_w, t_link *temp_f, t_vm *vm, int index);
int	check_vm_champs(t_vm *vm, t_processus *temp_p, t_link *temp_w);
int	check_memory_space(t_vm *vm, int low, int high);
int	check_and_fill_vm(t_vm *vm, t_help *help,
                          t_processus *temp_p, t_link *temp_w);
void	execute_command(t_processus *temp, unsigned char p_code);
int	execute_cycle(t_vm *vm, t_game *counters, int size_l);
int	start_game(t_vm *vm);
int	*get_processes_ids(t_vm *vm, int size_l);

#endif /* !VM_FUNCTIONS_H_ */
