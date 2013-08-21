/*
** my_str_to_wordtab.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Wed Oct 10 19:43:10 2012 julien regnier
** Last update Sat Dec 15 16:09:13 2012 julien regnier
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_str_to_wordtab.h"

int	get_nb_str(char *str, char c)
{
  int	i;
  int	nb_words;

  i = 0;
  nb_words = 0;
  while (str[i])
    {
      while (str[i] == ' ' || str[i] == '\t' || str[i] == c)
        i = i + 1;
      while (str[i] != 0 && (str[i] >= '!' && str[i] <= '~'))
      {
        if (str[i] == c && (str[i + 1] >= '!' && str[i + 1] <= '~'))
          nb_words = nb_words + 1;
        i = i + 1;
      }
      nb_words = nb_words + 1;
    }
  return (nb_words);
}

void	my_memset(char *word, int size)
{
  int	i;

  i = 0;
  while (i < size)
  {
    word[i] = 0;
    i = i + 1;
  }
}

void	get_my_str(char *str, char *word, char **tab, int t[4])
{
  while (str[t[I]])
    {
      my_memset(word, my_strlen(str));
      while (str[t[I]] != 0 && str[t[I]] >= '!'
            && str[t[I]] <= '~' && str[t[I]] != (char)t[CHAR])
	{
	  word[t[I_WORD]] = str[t[I]];
	  t[I] = t[I] + 1;
	  t[I_WORD] = t[I_WORD] + 1;
	}
      if (t[I_WORD] == 0)
	t[I] = t[I] + 1;
      else
	{
          word[t[I_WORD]] = 0;
	  tab[t[NB_WORD]] = my_strdup(word);
	  t[NB_WORD] = t[NB_WORD] + 1;
          t[I_WORD] = 0;
	}
    }
  tab[t[NB_WORD]] = NULL;
}

char	**my_str_to_wordtab(char *str, char c)
{
  char	**tab;
  char	*word;
  int	nb_words;
  int	tab1[4];

  tab1[I] = 0;
  tab1[NB_WORD] = 0;
  tab1[I_WORD] = 0;
  tab1[CHAR] = c;
  if (my_strlen(str) <= 0)
    return (NULL);
  nb_words = get_nb_str(str, c);
  tab = malloc((nb_words + 1) * sizeof(char *));
  if (tab == NULL)
    return (NULL);
  word = malloc(my_strlen(str));
  if (word == NULL)
    return (NULL);
  get_my_str(str, word, tab, tab1);
  free(word);
  return (tab);
}
