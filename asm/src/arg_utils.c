/*
** arg_utils.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/src
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Mon Dec 10 13:51:13 2012 Marin Alcaraz
** Last update Sat Dec 15 17:18:31 2012 olivier chapeau
*/

#include <stdio.h>
#include <stdlib.h>
#include "instruction.h"
#include "op.h"
#include "my.h"
#include "label.h"
#include "label_utils.h"

int     id_param(char *param)
{
  if ((param[0] == 'r')
      && (my_getnbr(param + 1) < REG_NUMBER))
    return (T_REG);
  else if (param[0] == DIRECT_CHAR
      && (is_plabel(param + 1)
        || my_getnbr(param + purgue_number(param))))
    return (T_DIR);
  else if ((is_plabel(param))
      || my_getnbr(param + purgue_number(param)))
    return (T_IND);
  return (0);
}

int         get_param_code(char *command, int index)
{
  op_t      *proxy;

  proxy = op_tab;
  while (my_strcmp(proxy->mnemonique, command) != 0)
    proxy = proxy + 1;
  return ((proxy)->type[index]);
}

int         get_param_type(char *command)
{
  op_t      *proxy;
  int       i;

  i = 0;
  proxy = op_tab;
  while (my_strcmp(proxy->mnemonique, command) != 0)
    proxy = proxy + 1;
  while ((proxy)->type[i] != 0)
    i = i + 1;
  return (i);
}

int     fix_compare(int current, int code)
{
  if (current == code)
    return (1);
  else if (code == (T_DIR + T_IND + T_REG))
  {
    if ((current == T_DIR)
        || (current == T_IND )|| (current == T_REG))
      return (1);
  }
  else if (code == (T_DIR + T_IND))
  {
    if ((current == T_DIR) || (current == T_IND))
      return (1);
  }
  else if (code == (T_IND + T_REG))
  {
    if ((current == T_IND) || (current == T_REG))
      return (1);
  }
  else if (code == (T_DIR + T_REG))
  {
    if ((current == T_DIR ) || (current == T_REG))
      return (1);
  }
  return (0);
}

int     valid_args(char **tab)
{
  int   i;
  int   spaces;
  int   translation;

  i = 0;
  translation = 0;
  spaces = get_param_type(tab[0]);
  while (i < spaces)
  {
    translation = id_param(tab[i + 1]);
    if (!(fix_compare(translation, get_param_code(tab[0], i))))
      return (0);
    i = i + 1;
  }
  return (1);
}
