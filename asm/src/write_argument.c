/*
** write_argument.c for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Sat Dec 15 17:25:32 2012 julien regnier
** Last update Sat Dec 15 18:12:56 2012 julien regnier
*/

#include "op.h"
#include "assemble.h"
#include "write_bytes.h"
#include "encoding_byte.h"
#include "label_utils.h"
#include "error.h"
#include "my.h"

extern t_parser	g_parser;
extern t_labels	*g_list;

static int	test_indirect(char **my_tab, int fd[2], int i)
{
  if (my_tab[i][0] == LABEL_CHAR)
  {
    if (get_add_lab(my_tab[i] + 1, g_list) == -1)
    {
      label_undefined(g_parser.line_nb, my_tab[i] + 1);
      return (1);
    }
    if (write_indirect_label(fd, my_tab[i], my_tab) == 1)
      return (1);
  }
  else
  {
    if (write_indirect_int(fd[1], my_tab[i]) == 1)
      return (1);
  }
  return (0);
}

static int	test_direct(char **my_tab, int fd[2], int i, int cmd)
{
  if ((!my_strcmp(my_tab[0], "sti") && i >= 2)
      || !my_strcmp(my_tab[0], "zjmp")
      || !my_strcmp(my_tab[0], "ldi")
      || !my_strcmp(my_tab[0], "lldi")
      || !my_strcmp(my_tab[0], "fork")
      || !my_strcmp(my_tab[0], "lfork"))
  {
    if (write_n_bytes(fd[1], &cmd, IND_SIZE) == 1)
      return (1);
  }
  else
  {
    if (write_n_bytes(fd[1], &cmd, DIR_SIZE) == 1)
      return (1);
  }
  return (0);
}

static int	test_direct_label(char **my_tab, int fd[2], int i)
{
  if (get_add_lab(my_tab[i] + 2, g_list) == -1)
  {
    label_undefined(g_parser.line_nb, my_tab[i] + 2);
    return (1);
  }
  if (write_direct_label(fd, my_tab[i], my_tab) == 1)
    return (1);
  return (0);
}

int		write_argument(char **my_tab, int fd[2], int i)
{
  int		cmd;

  cmd = my_getnbr(my_tab[i] + 1);
  if (my_tab[i][0] == 'r')
  {
    if (write_n_bytes(fd[1], &cmd, 1) == 1)
      return (1);
  }
  else if (my_tab[i][0] == DIRECT_CHAR && my_tab[i][1] == LABEL_CHAR)
  {
    if (test_direct_label(my_tab, fd, i) == 1)
      return (1);
  }
  else if (my_tab[i][0] == DIRECT_CHAR)
  {
    if (test_direct(my_tab, fd, i, cmd) == 1)
      return (1);
  }
  else
    if (test_indirect(my_tab, fd, i) == 1)
      return (1);
  return (0);
}
