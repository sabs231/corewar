/*
** error.c for src in /home/regnie_j/corewar/src
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 03 15:57:36 2012 julien regnier
** Last update Sat Dec 15 17:18:23 2012 julien regnier
*/

#include "my.h"

void	syntax_error(int line_nb)
{
  my_putstr_err("Syntax error line ", 2);
  my_putnbr_err(line_nb, 2);
}

void	label_error(int line_nb, char *label)
{
  my_putstr("label ");
  my_putstr(label);
  my_putstr_err(" undeﬁne line ", 2);
  my_putnbr_err(line_nb, 2);
}

void	label_already_error(int line_nb, char *label)
{
  my_putstr("label ");
  my_putstr(label);
  my_putstr_err(" redeﬁne line ", 2);
  my_putnbr_err(line_nb, 2);
}

void	label_undefined(int line_nb, char *label)
{
  my_putstr("label ");
  my_putstr(label);
  my_putstr_err(" undefine line ", 2);
  my_putnbr_err(line_nb, 2);
}
