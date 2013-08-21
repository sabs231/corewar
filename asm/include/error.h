/*
** error.h for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 03 15:58:38 2012 julien regnier
** Last update Sat Dec 15 15:30:18 2012 julien regnier
*/

#ifndef ERROR_H_
# define ERROR_H_

void	syntax_error(int line_nb);
void	label_error(int line_nb, char *label);
void	label_already_error(int line_nb, char *label);
void	label_undefined(int line_nb, char *label);

#endif /* !ERROR_H_ */
