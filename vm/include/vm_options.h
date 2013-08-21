/*
** vm_options.h for include in /home/chapea_o/travail/corewar/src/include
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Tue Dec 04 15:57:19 2012 olivier chapeau
** Last update Mon Dec 10 17:18:10 2012 olivier chapeau
*/

#ifndef VM_OPTIONS_H_
# define VM_OPTIONS_H_

# include "vm.h"
# include "list.h"

# define MAX_CHAMPIONS  4
# define VM_NB_OPTIONS	3

enum	e_flags
{
  DUMP
} ;

struct	s_options
{
  char	*option;
  int	(*f)(char **argv, t_vm *vm, int *i);
} ;

typedef struct s_options t_options;

int	insert_warrior_in_vm(t_vm *vm, int id, int pc);
int	insert_file_in_vm(t_vm *vm, t_list *files, char *name);
int	get_options(int argc, char **argv, t_vm *vm, t_list *files);
int	get_dump(char **argv, t_vm *vm, int *i);
int	get_warrior_id(char **argv, t_vm *vm, int *i);
int	get_warrior_address(char **argv, t_vm *vm, int *i);

#endif /* !VM_OPTIONS_H_ */
