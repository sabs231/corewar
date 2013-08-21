/*
** vm_instructions.h for include in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/include
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Tue Dec 11 14:13:43 2012 olivier chapeau
** Last update Sun Dec 16 17:06:54 2012 olivier chapeau
*/

#ifndef VM_INSTRUCTIONS_H_
# define VM_INSTRUCTIONS_H_

# include "op.h"
# include "vm.h"

# define PARAM1	0xC0
# define PARAM2	0x30
# define PARAM3	0x0C

void	add(t_vm *vm, int id);
void	sub(t_vm *vm, int id);
void	and(t_vm *vm, int id);
void	or(t_vm *vm, int id);
void	xor(t_vm *vm, int id);
void	ld(t_vm *vm, int id);
void	st(t_vm *vm, int id);
void	ldi(t_vm *vm, int id);
void	sti(t_vm *vm, int id);
void	live(t_vm *vm, int id);
void	zjump(t_vm *vm, int id);
void	aff(t_vm *vm, int id);
void	lld(t_vm *vm, int id);
void	lldi(t_vm *vm, int id);
void	lfork(t_vm *vm, int id);

#endif /* !VM_INSTRUCTIONS_H_ */
