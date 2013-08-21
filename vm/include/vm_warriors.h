/*
** vm_warriors.h for include in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/include
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Thu Dec 06 19:22:25 2012 olivier chapeau
** Last update Tue Dec 11 16:56:53 2012 olivier chapeau
*/

#ifndef VM_WARRIORS_H_
# define VM_WARRIORS_H_

# include "op.h"
# include "vm_bool.h"
# include "vm.h"

struct		s_warrior
{
  unsigned int	id;
  header_t	header;
  vm_bool	is_alive;
} ;

typedef struct s_warrior t_warrior;

t_warrior	*new_warrior(void);
void		insert_header(t_warrior *warrior, header_t *header);
t_warrior	*get_warrior_by_id(t_vm *vm, unsigned int id);

#endif /* !VM_WARRIORS_H_ */
