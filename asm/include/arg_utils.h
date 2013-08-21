/*
** arg_utils.h for include in /home/regnie_j/corewar/include
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Mon Dec 10 17:49:31 2012 Marin Alcaraz
** Last update Sat Dec 15 19:31:13 2012 julien regnier
*/

#ifndef ARG_UTILS_H_
# define ARG_UTILS_H_

int         get_param_type(char *command);
int         id_param(char *param);
int         get_param_code(char *command, int index);
int         valid_args(char **tab);

#endif /* !ARG_UTILS_H_ */
