/*
** my.h for my in /home/regnie_j/corewar/my
**
** Made by julien regnier
** Login   <regnie_j@epitech.net>
**
** Started on  Thu Oct 11 09:48:28 2012 julien regnier
** Last update Thu Dec 13 14:31:10 2012 julien regnier
*/

#ifndef MY_H_
# define MY_H_

# define NUMBER_CHAR 1

char	**my_str_to_wordtab(char *str, char c);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_putstr_err(char *str, int fd);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_strdup(char *str);
char	*my_strncpy(char *dest, char *src, int n);
char	*get_next_line(const int fd);
void	my_putnbr_err(int nb, int fd);
void	swap_bytes(char *bytes, int size);

#endif /* !MY_H_ */
