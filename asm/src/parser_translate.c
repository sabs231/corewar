/*
** parser_translate.c for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 10 13:48:48 2012 julien regnier
** Last update Sat Dec 15 18:17:15 2012 julien regnier
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "label.h"
#include "my.h"
#include "get.h"
#include "op.h"
#include "assemble.h"
#include "parser_instruction.h"
#include "compressor.h"
#include "instruction.h"
#include "write_instruction.h"

t_parser	g_parser;

static int 	parse_label(char **my_tab)
{
  char		**temp;

  if (my_tab && my_tab[0] && my_tab[0][0] != '\n'
      && my_tab[0][0] != COMMENT_CHAR)
  {
    temp = my_tab + 1;
    if (is_label(my_tab[0]) == 1 && my_tab[1] != NULL)
    {
      if (compressor(&temp) == 1)
      {
        my_putstr_err("Can’t perform malloc", 2);
        return (1);
      }
    }
    else
    {
      if (compressor(&my_tab) == 1)
      {
        my_putstr_err("Can’t perform malloc", 2);
        return (1);
      }
    }
  }
  return (0);
}

static int	free_and_return(char **my_tab, char *line)
{
  free_tab(my_tab);
  free(line);
  return (1);
}

int		parse_and_translate(int fd[2])
{
  char		*line;
  char		**my_tab;

  g_parser.line_nb = 0;
  g_parser.current_address = 0;
  line = get_next_instruction(fd[0], &g_parser);
  while (line != NULL)
  {
    my_tab = my_str_to_wordtab(line, SEPARATOR_CHAR);
    if (parse_label(my_tab) == 1)
      return (free_and_return(my_tab, line));
    if (my_tab[0] && my_tab[0][0] != '\0' && my_tab[0][0] != COMMENT_CHAR)
    {
      if (write_instruction((is_label(my_tab[0]) == 1) ? my_tab + 1 :
            my_tab, fd) == 1)
        return (1);
      g_parser.current_address += get_incsize(my_tab);
    }
    g_parser.line_nb += 1;
    free_tab(my_tab);
    free(line);
    line = get_next_instruction(fd[0], &g_parser);
  }
  return (0);
}
