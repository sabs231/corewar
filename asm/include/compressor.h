/*
** compressor.h for include in /home/regnie_j/corewar/include
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Sun Dec 09 19:18:08 2012 Marin Alcaraz
** Last update Sat Dec 15 19:34:02 2012 julien regnier
*/

#ifndef COMPRESSOR_H_
# define COMPRESSOR_H_

char	*append(char *s1, char *s2, char glue);
char	*paste(char *new, char *src, char glue, int *index);
int	compressor(char ***tab);

#endif /* !COMPRESSOR_H_ */
