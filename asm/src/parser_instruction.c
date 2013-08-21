/*
** parser_instruction.c for src in /home/regnie_j/corewar/src
**
** Made by julien regnier
** Login   <regnie_j@epitech.net>
**
** Started on  Mon Dec 03 18:43:48 2012 julien regnier
** Last update Sat Dec 15 18:12:40 2012 julien regnier
*/

#include <stdio.h>
#include <stdlib.h>
#include "get.h"
#include "op.h"
#include "my.h"
#include "label.h"
#include "instruction.h"
#include "assemble.h"
#include "error.h"
#include "compressor.h"
#include "arg_utils.h"

static int	syntax_error_and_return(int line_nb)
{
      syntax_error(line_nb);
      return (1);
}

static int	parse_line_instruction(t_parser *parser, char **my_tab)
{
  if (is_defined(my_tab[0]) == 1)
  {
    if (compressor(&my_tab) == 1)
    {
      my_putstr_err("Can’t perform malloc", 2);
      return (1);
    }
    if (is_number_valid(my_tab, my_tab[0]) == 1)
      parser->current_address += get_incsize(my_tab);
    else
      return (syntax_error_and_return(parser->line_nb));
    if (valid_args(my_tab) == 0)
      return (syntax_error_and_return(parser->line_nb));
  }
  else
    return (syntax_error_and_return(parser->line_nb));
  return (0);
}

static int 	parse_label(t_parser *parser, char **my_tab, t_labels **list)
{
  if (my_tab && my_tab[0] && my_tab[0][0] != '\n'
      && my_tab[0][0] != COMMENT_CHAR)
  {
    if (is_label(my_tab[0]) == 1)
    {
      if (exist(my_tab[0], (*list)) == 1)
      {
        label_already_error(parser->line_nb, my_tab[0]);
        return (1);
      }
      else
      {
        if (add_label(my_tab[0], parser->current_address, list) == 0)
          return (1);
        if (my_tab[1] != NULL)
          parse_line_instruction(parser, my_tab + 1);
      }
    }
    else
    {
      if (parse_line_instruction(parser, my_tab) == 1)
        return (1);
    }
  }
  return (0);
}

void		free_tab(char **my_tab)
{
  int		i;

  i = 0;
  while (my_tab[i])
  {
    free(my_tab[i]);
    i = i + 1;
  }
  free(my_tab);
}

int		parse_instruction(int fd_src, t_parser *parser, t_labels **list)
{
  char		*line;
  char		**my_tab;

  line = get_next_instruction(fd_src, parser);
  while (line != NULL)
  {
    my_tab = my_str_to_wordtab(line, SEPARATOR_CHAR);
    if (parse_label(parser, my_tab, list) == 1)
    {
      free_tab(my_tab);
      free(line);
      return (1);
    }
    free_tab(my_tab);
    free(line);
    line = get_next_instruction(fd_src, parser);
  }
  return (0);
}
