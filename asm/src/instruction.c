/*
** instruction.c for src in /home/regnie_j/corewar/src
**
** Made by julien regnier
** Login   <regnie_j@epitech.net>
**
** Started on  Wed Dec 05 18:09:23 2012 julien regnier
** Last update Sat Dec 15 19:24:44 2012 julien regnier
*/

#include <stdlib.h>
#include "get.h"
#include "op.h"
#include "my.h"
#include "label.h"
#include "assemble.h"
#include "error.h"
#include "instruction.h"
#include "arg_utils.h"

int		get_param_number(char *cmd)
{
  op_t		*proxy;

  proxy = op_tab;
  while (proxy->code != 0)
  {
    if (my_strcmp((proxy)->mnemonique, cmd) == 0)
      return (proxy->nbr_args);
   proxy = proxy + 1;
  }
  return (0);
}

int		is_number_valid(char **words, char *command)
{
  int 	i;
  int   j;
  int	fun_args;

  i = 0;
  j = 0;
  fun_args = get_param_number(command);
  while (words[j] != NULL)
  {
    if (words[j][0] != '\0')
      i = i + 1;
    j = j + 1;
  }
  if (fun_args == (i - 1))
    return (1);
  else
    return (0);
}

int		is_defined(char *s)
{
  op_t		*proxy;

  proxy = op_tab;
  while (proxy->code != 0)
  {
    if (my_strcmp((proxy)->mnemonique, s) == 0)
      return (1);
   proxy = proxy + 1;
  }
  return (0);
}

static int	get_incsize_aux(char **t)
{
  int		i;
  int		val;

  i = 0;
  if (t[i] == NULL)
    return (0);
  val = 1;
  if (!(my_strcmp(t[i], "fork") == 0 || my_strcmp(t[i], "lfork") == 0
        || my_strcmp(t[i], "live") == 0 || my_strcmp(t[i], "zjmp") == 0))
    val = val + 1;
  while (t[++i])
  {
    if (id_param(t[i]) == T_REG)
      val = val + 1;
    else if (id_param(t[i]) == T_DIR)
      val = ((!my_strcmp(t[0], "fork") || !my_strcmp(t[0], "zjmp")
            || !my_strcmp(t[0], "ldi") || !my_strcmp(t[0], "sti")
            || !my_strcmp(t[0], "lldi") || !my_strcmp(t[0], "lfork")) ?
          val + IND_SIZE : val + DIR_SIZE);
    else
      val = val + IND_SIZE;
  }
  return (val);
}

int		get_incsize(char **t)
{
  if (is_label(t[0]) == 1)
    return (get_incsize_aux(t + 1));
  else
    return (get_incsize_aux(t));
}
