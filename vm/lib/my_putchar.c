/*
** my_putchar.c for my_putchar in /home/chapea_o//travail/rendu/lib/
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Wed Oct  3 09:34:36 2012 olivier chapeau
** Last update Tue Oct  9 09:50:03 2012 olivier chapeau
*/

#include <unistd.h>

int	my_putchar(char c)
{
  return (write (1, &c, 1));
}
