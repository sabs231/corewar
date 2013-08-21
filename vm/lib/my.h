/*
** my.h for lib in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/lib
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Thu Oct 11 10:30:25 2012 olivier chapeau
** Last update Sun Dec 16 17:02:23 2012 olivier chapeau
*/

#ifndef MY_H_
# define MY_H_

# include "vm.h"
# define STDIN	0
# define STDOUT	1
# define STDERR	2

int	my_fputstr(int fd, char *str);
int	my_putchar(int i);
int	my_fputchar(int fd, char c);
void	my_fputnbr(int fd, int nb);
int	my_putstr(char *str);
void	my_reset_str(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
void	my_strncpy(t_vm *vm, unsigned char *src, int n, int pc);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_revstr(char *str);
int	my_get_unsigned_nbr(char *str);
void	my_put_nbr(int nbr);
void	my_putnbr_base(int nbr, char *base);

#endif /* !MY_H_ */
