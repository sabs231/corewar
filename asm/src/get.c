/*
** get.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 03 12:37:20 2012 julien regnier
** Last update Sat Dec 15 17:23:27 2012 olivier chapeau
*/

#include <stdlib.h>
#include "op.h"
#include "error.h"
#include "my.h"
#include "assemble.h"

char	*get_new_name(char *name)
{
  int	len;
  char	*new_name;

  len = my_strlen(name);
  if ((new_name = malloc(len + 3)) == NULL)
  {
    my_putstr_err("Can’t perform malloc", 2);
    return (NULL);
  }
  my_strncpy(new_name, name, len);
  new_name[len - 1] = '\0';
  my_strncat(new_name, "cor\0", 4);
  return (new_name);
}

char	*get_next_instruction(int fd_src, t_parser *parser)
{
  char	*line;

  line = get_next_line(fd_src);
  parser->line_nb = parser->line_nb + 1;
  while (line && (line[0] == '\n' || line[0] == COMMENT_CHAR || line[0] == 0))
  {
    free(line);
    line = get_next_line(fd_src);
    parser->line_nb = parser->line_nb + 1;
  }
  if (line == NULL)
    return (NULL);
  line[my_strlen(line)] = '\0';
  return (line);
}

int		get_nb_args_mnemonique(char *mnemonique)
{
  op_t		*proxy;

  proxy = op_tab;
  while (proxy->code != 0)
  {
    if (my_strcmp((proxy)->mnemonique, mnemonique) == 0)
      return (proxy->nbr_args);
    proxy = proxy + 1;
  }
  return (-1);
}

char	*get_first_word(char *str)
{
  int	i;
  char	*new;

  i = 0;
  while (str && (*str == ' ' || *str == '\t'))
    str = str + 1;
  i = 0;
  while (str && str[i] && str[i] != ' ' && str[i] != '\t')
    i = i + 1;
  new = malloc(i + 1);
  if (new == NULL)
    return (NULL);
  i = 0;
  while (str && str[i] && str[i] != ' ' && str[i] != '\t')
  {
    new[i] = str[i];
    i = i + 1;
  }
  new[i] = '\0';
  return (new);
}
