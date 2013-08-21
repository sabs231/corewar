/*
** get_addr.c for src in /home/regnie_j/corewar/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Sat Dec 15 18:05:36 2012 olivier chapeau
** Last update Sat Dec 15 19:05:57 2012 julien regnier
*/

#include <stdlib.h>
#include "label_utils.h"
#include "get.h"
#include "my.h"
#include "parser_instruction.h"
#include "instruction.h"
#include "get_addr.h"

extern t_parser	g_parser;
extern t_labels	*g_list;

static	int	free_and_return(char *line, t_parser *parser)
{
  free(line);
  return (parser->current_address - 1);
}

static	void	frees(char **ltab, char *line)
{
  free_tab(ltab);
  free(line);
}

int		get_addr(int fd_src, char *ag, char **ltab)
{
  char		*line;
  char		*first;
  t_parser	parser;

  if (get_add_lab(ag, g_list) == g_parser.current_address)
    return (0);
  parser.current_address = 1;
  if (ltab[0] && ltab[0][0] != '\0' && ltab[0][0] != COMMENT_CHAR)
    parser.current_address += get_incsize(ltab);
  if ((line = get_next_instruction(fd_src, &parser)) == NULL)
    return (get_add_lab(ag, g_list) - g_parser.current_address);
  while (line != NULL)
  {
    if ((first = get_first_word(line)) == NULL)
      return (free_and_return(line, &parser));
    free(first);
    if ((!my_strncmp(ag, first, my_strlen(ag)) && first[my_strlen(ag)] == L))
      return (free_and_return(line, &parser));
    ltab = my_str_to_wordtab(line, ',');
    if (ltab && ltab[0] && ltab[0][0] != '\0' && ltab[0][0] != COMMENT_CHAR)
      parser.current_address += get_incsize(ltab);
    frees(ltab, line);
    line = get_next_instruction(fd_src, &parser);
  }
  return (get_add_lab(ag, g_list) - g_parser.current_address);
}
