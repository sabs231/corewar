/*
** my_fputchar.c for lib in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/lib
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Wed Oct  3 09:34:36 2012 olivier chapeau
** Last update Tue Dec 11 18:20:21 2012 olivier chapeau
*/

#include <unistd.h>

int	my_fputchar(int fd, char c)
{
    return (write(fd, &c, 1));
}
