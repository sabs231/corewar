/*
** my_str_to_wordtab.h for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.eu>
** 
** Started on  11/03/12 23:18:37 2012 julien regnier
** Last update Wed Dec 05 09:30:47 2012 julien regnier
*/

#ifndef   MY_STR_TO_WORDTAB_H_
# define  MY_STR_TO_WORDTAB_H_

enum	e_wordtab
{
  	I,
  	NB_WORD,
  	I_WORD,
  	CHAR
} ;

int	get_nb_str(char *str, char c);
void	reset_str(char *word);
void	get_my_str(char *str, char *word, char **tab, int tab1[4]);
char	**my_str_to_wordtab(char *str, char c);

#endif /* !__MY_STR_TO_WORDTAB_H_ */
