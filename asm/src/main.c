/*
** main.c for src in /home/regnie_j/corewar/src
**
** Made by julien regnier
** Login   <regnie_j@epitech.net>
**
** Started on  Mon Dec 03 10:52:23 2012 julien regnier
** Last update Sat Dec 15 17:44:45 2012 julien regnier
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "assemble.h"

static char	*check_file(char *name, int *fd_src)
{
  char		*test_name;
  int		len;

  len = my_strlen(name);
  test_name = malloc(len + 3);
  my_strncpy(test_name, name, len);
  if (name[len - 2] == '.' && name[len - 1] == 's')
  {
    my_strncat(test_name, "\0\0\0", 3);
    if (((*fd_src) = open(name, O_RDONLY)) == -1)
      return (NULL);
  }
  else
  {
    my_strncat(test_name, ".s\0", 3);
    if (((*fd_src) = open(test_name, O_RDONLY)) == -1)
      return (NULL);
  }
  return (test_name);
}

static int	usage(int argc, char **argv)
{
  if (argc < 2)
  {
    my_putstr_err("Usage: ", 2);
    my_putstr_err(argv[0], 2);
    my_putstr_err(" <file_name>\n", 2);
    return (1);
  }
  return (0);
}

int		main(int argc, char **argv)
{
  int		fd_src;
  char		*new_name;
  int		i;

  if (usage(argc, argv) == 1)
    return (1);
  i = 1;
  while (i < argc)
  {
    if ((new_name = check_file(argv[i], &fd_src)) == NULL)
    {
      my_putstr_err("File ", 2);
      my_putstr_err(argv[i], 2);
      my_putstr_err(" not accessible\n", 2);
    }
    else if (assemble(fd_src, new_name) == 1)
    {
      my_putstr_err(" in ", 2);
      my_putstr_err(argv[i], 2);
      my_putstr_err("\n", 2);
    }
    free(new_name);
    i = i + 1;
  }
  return (0);
}
