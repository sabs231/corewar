/*
** parser_header.h for include in /home/regnie_j/corewar/include
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Mon Dec 03 18:04:52 2012 julien regnier
** Last update Sat Dec 15 19:33:11 2012 julien regnier
*/

#ifndef PARSER_HEADER_H_
# define PARSER_HEADER_H_

# include "op.h"

int	parse_header(int fd_src, t_parser *parser,
    		     header_t *header, int *size);

#endif /* !PARSER_HEADER_H_ */
