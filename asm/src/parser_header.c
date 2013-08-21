/*
** parser_header.c for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 03 12:10:32 2012 julien regnier
** Last update Sat Dec 15 13:41:38 2012 julien regnier
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "op.h"
#include "error.h"
#include "get.h"

static int	flushncpy(char *dest, char *src, int size)
{
  int		i;

  i = 0;
  while (src && (*src == ' ' || *src == '\t'))
    src = src + 1;
  if (src && *src != '\"')
    return (1);
  src = src + 1;
  while (i < size)
  {
    if (*src == 0)
      dest[i] = 0;
    else
    {
      dest[i] = *src;
      src = src + 1;
    }
    i = i + 1;
  }
  if (my_strlen(dest) < size && dest[my_strlen(dest) - 1] != '\"')
    return (1);
  dest[my_strlen(dest) - 1] = 0;
  return (0);
}

static int	parse_header_line(char *line, char *str, char *name)
{
  if (my_strncmp(line, str, my_strlen(str)) != 0)
    return (1);
  if (flushncpy(name, line + my_strlen(str) + 1, PROG_NAME_LENGTH) == 1)
    return (1);
  return (0);
}

static void	reset_str(char *str, int size)
{
  int		i;

  i = 0;
  while (i < size)
  {
    str[i] = '\0';
    i = i + 1;
  }
}

static char	*get_next_size(int fd_src, t_parser *parser, int *size)
{
  char		*line;

  line = get_next_line(fd_src);
  parser->line_nb = parser->line_nb + 1;
  while (line && (line[0] == '\n' || line[0] == COMMENT_CHAR || line[0] == 0))
  {
    line[my_strlen(line)] = '\0';
    *size = *size + my_strlen(line) + 1;
    free(line);
    line = get_next_line(fd_src);
    parser->line_nb = parser->line_nb + 1;
  }
  if (line == NULL)
    return (NULL);
  line[my_strlen(line)] = '\0';
  *size = *size + my_strlen(line) + 1;
  return (line);
}

int		parse_header(int fd_src, t_parser *parser,
                             header_t *header, int *size)
{
  char		*line;

  reset_str(header->comment, COMMENT_LENGTH + 1);
  if ((line = get_next_size(fd_src, parser, size)) == NULL)
    return (1);
  if (parse_header_line(line, NAME_CMD_STRING, header->prog_name) == 1)
  {
    syntax_error(parser->line_nb);
    return (1);
  }
  free(line);
  header->prog_size = 0;
  if ((line = get_next_size(fd_src, parser, size)) == NULL)
    return (1);
  if (parse_header_line(line, COMMENT_CMD_STRING, header->comment) == 1)
  {
    syntax_error(parser->line_nb);
    return (1);
  }
  free(line);
  return (0);
}
