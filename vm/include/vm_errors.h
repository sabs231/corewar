/*
** vm_errors.h for include in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/include
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Dec 03 12:49:03 2012 olivier chapeau
** Last update Sat Dec 15 11:29:09 2012 sergioandres baezserrano
*/

#ifndef VM_ERRORS_H_
# define VM_ERRORS_H_

# define SUCCESS	0
# define EOPEN		1
# define ECLOSE		2
# define EREAD		3
# define EMALLOC	4
# define ETMCHAMPIONS	5
# define ENOT_COR_EXE	6
# define E_ID_USED	7
# define ESIZE		8
# define EID_PROCESS	9
# define EOVERLAP	10
# define ENOPROCESS	11
# define VM_NB_ERRORS	11
# define EUSAGE		12

struct	s_errors
{
  int	err_num;
  char	*msg;
} ;

typedef struct s_errors t_errors;

void	vm_display_errors(int err_num, char *string);

#endif /* !VM_ERRORS_H_ */
