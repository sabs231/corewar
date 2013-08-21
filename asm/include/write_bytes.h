/*
** write_bytes.h for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Tue Dec 11 16:05:13 2012 julien regnier
** Last update Sat Dec 15 16:11:07 2012 julien regnier
*/

#ifndef WRITE_BYTES_H_
# define WRITE_BYTES_H_

# include "label_struct.h"

int	write_n_bytes(int fd_dest, int *nb, int size);
int	write_direct_label(int fd[2], char *arg, char **my_tab);
int	write_indirect_label(int fd[2], char *arg, char **my_tab);
int	write_indirect_int(int fd_dest, char *arg);

#endif /* !WRITE_BYTES_H_ */
