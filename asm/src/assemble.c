/*
** assemble.c for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 03 12:01:49 2012 julien regnier
** Last update Sat Dec 15 19:07:54 2012 julien regnier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "get.h"
#include "parser_header.h"
#include "parser_instruction.h"
#include "parser_translate.h"
#include "op.h"
#include "assemble.h"
#include "label.h"
#include "write_instruction.h"

t_labels	*g_list;

static int	write_header(int fd_dest, header_t *header, t_parser *parser)
{
  int		magic;
  int		prog_size;

  magic = COREWAR_EXEC_MAGIC;
  swap_bytes((char *)&magic, sizeof(magic));
  header->magic = magic;
  prog_size = parser->current_address;
  swap_bytes((char *)&prog_size, sizeof(int));
  header->prog_size = prog_size;
  if (write(fd_dest, header, sizeof(*header)) == -1)
  {
    my_putstr_err("Cannot write in the file", 2);
    return (1);
  }
  return (0);
}

static int	parse_file(int fd_src, t_parser *parser,
                           int fd_dest, header_t *header)
{
  int		fd[2];
  int		size_header;
  char		*temp;

  fd[0] = fd_src;
  fd[1] = fd_dest;
  g_list = NULL;
  parser->line_nb = 0;
  parser->current_address = 0;
  size_header = 0;
  if (parse_header(fd_src, parser, header, &size_header) == 1
      || parse_instruction(fd_src, parser, &g_list) == 1
      || write_header(fd_dest, header, parser) == 1)
    return (1);
  if (lseek(fd_src, 0, SEEK_SET) == -1)
    return (1);
  if ((temp = malloc(size_header)) == NULL)
    return (1);
  if (read(fd[0], temp, size_header) == -1)
    return (1);
  free(temp);
  if (parse_and_translate(fd) == 1)
    return (1);
  free_list(&g_list);
  return (0);
}

int		assemble(int fd_src, char *name)
{
  int		fd_dest;
  char		*new_name;
  header_t	header;
  t_parser	parser;

  if ((new_name = get_new_name(name)) == NULL)
    return (1);
  if ((fd_dest = open(new_name, O_WRONLY | O_CREAT | O_TRUNC, 00600)) == -1)
  {
    my_putstr_err("Can't create the .cor file", 2);
    return (1);
  }
  if (parse_file(fd_src, &parser, fd_dest, &header) == 1)
    return (1);
  free(new_name);
  if (close(fd_dest) == -1)
    return (1);
  if (close(fd_src) == -1)
    return (1);
  return (0);
}
