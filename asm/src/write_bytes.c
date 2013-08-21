/*
** write_bytes.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Tue Dec 11 15:58:49 2012 julien regnier
** Last update Sat Dec 15 18:31:33 2012 olivier chapeau
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "get.h"
#include "label_struct.h"
#include "instruction.h"
#include "assemble.h"
#include "parser_instruction.h"
#include "parser_header.h"
#include "label.h"
#include "label_utils.h"
#include "get_addr.h"

extern t_parser	g_parser;
extern t_labels	*g_list;

int		write_n_bytes(int fd_dest, int *nb, int size)
{
  short int	temp;

  if (size <= 0)
    return (1);
  temp = *nb;
  if (size > 2)
    swap_bytes((char *)nb, sizeof(*nb));
  if (size == 2)
  {
    swap_bytes((char *)&temp, sizeof(temp));
    if (write(fd_dest, &temp, size) == -1)
      return (1);
  }
  else
  {
    if (write(fd_dest, nb, size) == -1)
      return (1);
  }
  return (0);
}

int		write_direct_label(int fd[2], char *arg, char **my_tab)
{
  int		addr;
  int		size;
  off_t		off;

  if ((off = lseek(fd[0], 0, SEEK_CUR)) == -1)
    return (1);
  size = DIR_SIZE;
  addr = get_addr(fd[0], arg + 2, my_tab);
  if (lseek(fd[0], off, SEEK_SET) == -1)
    return (1);
  if (my_strcmp(my_tab[0], "fork") == 0 || my_strcmp(my_tab[0], "zjmp") == 0
      || my_strcmp(my_tab[0], "ldi") == 0 || my_strcmp(my_tab[0], "sti") == 0)
    size = IND_SIZE;
  if (write_n_bytes(fd[1], &addr, size) == 1)
    return (1);
  return (0);
}

int		write_indirect_label(int fd[2], char *arg, char **my_tab)
{
  int		addr;
  off_t		off;

  if ((off = lseek(fd[0], 0, SEEK_CUR)) == -1)
    return (1);
  addr = get_addr(fd[0], arg + 1, my_tab);
  if (lseek(fd[0], off, SEEK_SET) == -1)
    return (1);
  if (write_n_bytes(fd[1], &addr, IND_SIZE) == 1)
    return (1);
  return (0);
}

int		write_indirect_int(int fd_dest, char *arg)
{
  int		cmd;

  cmd = my_getnbr(arg);
  if (write_n_bytes(fd_dest, &cmd, IND_SIZE) == 1)
    return (1);
  return (0);
}
