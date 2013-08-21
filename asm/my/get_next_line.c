/*
** get_next_line.c for my in /home/regnie_j/corewar/my
**
** Made by julien regnier
** Login   <regnie_j@epitech.net>
**
** Started on  Thu Nov 22 09:57:42 2012 julien regnier
** Last update Mon Dec 10 18:36:46 2012 julien regnier
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int	my_reallocncpy(char *buf, char **line, int *indice)
{
  int		i;
  int		j;
  char		*tmp;

  tmp = *line;
  if ((*line = malloc(my_strlen(*line) + my_strlen(buf) + 1)) == NULL)
    return (2);
  i = 0;
  while (tmp != NULL && tmp[i])
  {
    (*line)[i] = tmp[i];
    i = i + 1;
  }
  j = 0;
  while (buf != NULL && buf[j] != '\n' && buf[j] != '\0')
  {
    (*line)[i] = buf[j];
    *indice = *indice + 1;
    i = i + 1;
    j = j + 1;
  }
  (*line)[i] = '\0';
  if (tmp != NULL)
    free(tmp);
  return ((buf[j] == '\0') ? 1 : 0);
}

static int	test_need_read(const int fd, char *buf, int *ret, int *indice)
{
  if (*indice >= NUMBER_CHAR)
  {
    *indice = 0;
    *ret = read(fd, buf, NUMBER_CHAR);
    buf[*ret] = '\0';
    if (*ret <= 0)
      return (1);
  }
  return (0);
}

static int	there_is_line_in_buf(int res, int *indice, char *line)
{
  if (res == 1 && *indice < NUMBER_CHAR)
  {
    *indice = NUMBER_CHAR;
    if (line[0] != '\0')
      return (1);
  }
  return (0);
}

char            *get_next_line(const int fd)
{
  static char	buf[NUMBER_CHAR];
  static int	indice = NUMBER_CHAR;
  char		*line;
  int		ret;
  int		res;

  line = NULL;
  res = 0;
  ret = NUMBER_CHAR;
  while (line == NULL || indice >= NUMBER_CHAR || res == 1)
  {
    if (test_need_read(fd, buf, &ret, &indice) == 1)
      return (NULL);
    if ((res = my_reallocncpy(buf + indice, &line, &indice)) == 2)
    {
      free(line);
      return (NULL);
    }
    if (there_is_line_in_buf(res, &indice, line) == 1)
      return (line);
  }
  indice = indice + 1;
  return (line);
}
