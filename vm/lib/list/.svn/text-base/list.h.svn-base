/*
** list.h for list in /home/chapea_o/travail/corewar/src/my/list
**
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
**
** Started on  Thu Dec 06 19:50:59 2012 olivier chapeau
** Last update Mon Dec 10 15:28:12 2012 olivier chapeau
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdlib.h>

struct		s_link
{
  void		*data;
  struct s_link	*next;
} ;

typedef struct s_link t_link;

struct		s_list
{
  t_link	*first;
} ;

typedef struct s_list t_list;

t_list		*new_list(void);
t_link		*new_link(void *data);
void		insert_in_list(t_list *list, void *data);
void            *delete_first(t_list *list);
t_link		*get_last_link(t_list *list);
int             size_list(t_list *list);
int		is_empty_list(t_list *list);
void            apply_in_list(t_list *list, void (*f)(void *));
void            clear_list(t_list **list);

#endif /* !LIST_H_ */
