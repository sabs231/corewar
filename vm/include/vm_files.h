/*
** vm_files.h for include in /home/chapea_o/travail/corewar/src/include
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Fri Dec 07 18:25:50 2012 olivier chapeau
** Last update Mon Dec 10 15:11:38 2012 olivier chapeau
*/

#ifndef VM_FILES_H_
# define VM_FILES_H_

struct	s_file
{
  char	*name;
  int	fd;
} ;

typedef struct s_file t_file;

t_file      *new_file(void);

#endif /* !VM_FILES_H_ */
