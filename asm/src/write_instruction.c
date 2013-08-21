/*
** write_instruction.c for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Tue Dec 11 09:51:43 2012 julien regnier
** Last update Sat Dec 15 19:16:43 2012 julien regnier
*/

#include <stdio.h>
#include <unistd.h>
#include "instruction.h"
#include "my.h"
#include "write_bytes.h"
#include "encoding_byte.h"
#include "get.h"
#include "write_argument.h"
#include "op.h"

static int	write_encoding_byte(char **my_tab, int fd_dest)
{
  int		nb_args;
  int		encoding_byte;

  if ((nb_args = (get_nb_args_mnemonique(my_tab[0]))) < 0)
    return (1);
  if (nb_args == 0)
    return (0);
  if (my_strcmp(my_tab[0], "live") != 0 && my_strcmp(my_tab[0], "zjmp") != 0
      &&
      my_strcmp(my_tab[0], "fork") != 0 && my_strcmp(my_tab[0], "lfork") != 0)
  {
    get_encoding_byte(my_tab + 1, &encoding_byte);
    if (write_n_bytes(fd_dest, &encoding_byte, 1) == 1)
      return (1);
  }
  return (0);
}

static int	write_mnemonique(char *mnemonique, int fd_dest)
{
  op_t		*proxy;
  int		temp;

  proxy = op_tab;
  while (proxy->code != 0)
  {
    if (my_strcmp((proxy)->mnemonique, mnemonique) == 0)
    {
      temp = proxy->code;
      if (write_n_bytes(fd_dest, &temp, 1) == -1)
        return (1);
      return (0);
    }
    proxy = proxy + 1;
  }
  return (1);
}

int		write_instruction(char **my_tab, int fd[2])
{
  int		i;

  if (my_tab && my_tab[0] && my_tab[0][0] != COMMENT_CHAR)
  {
    i = 0;
    while (my_tab[i])
    {
      if (my_tab[i][0] != '\0')
      {
        if (is_defined(my_tab[i]) == 1)
        {
          if (write_mnemonique(my_tab[i], fd[1]) == 1)
            return (1);
          if (write_encoding_byte(my_tab, fd[1]) == 1)
            return (1);
        }
        else
          if (write_argument(my_tab, fd, i) == 1)
            return (1);
      }
      i = i + 1;
    }
  }
  return (0);
}
