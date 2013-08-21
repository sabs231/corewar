/*
** vm_instructions_utils.c for src in /home/chapea_o/travail/corewar/git_corewar/corewar/vm/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Thu Dec 13 18:24:31 2012 olivier chapeau
** Last update Fri Dec 14 17:00:59 2012 olivier chapeau
*/

#include "vm.h"

int		check_encoding_byte(unsigned char encoding_byte)
{
  unsigned char	tmp;

  printf("encoding byte: %02x\n", encoding_byte);
  if ((tmp = encoding_byte & 0xC0) == 0x40)
    printf("1 - registre\n");
  else if (tmp == 0x80)
    printf("1 - direct\n");
  else if (tmp == 0xC0)
    printf("1 - indirect\n");
  if ((tmp = encoding_byte & 0x30) == 0x10)
    printf("2 - registre\n");
  else if (tmp == 0x20)
    printf("2 - direct\n");
  else if (tmp == 0x30)
    printf("2 - indirect\n");
  if ((tmp = encoding_byte & 0x0C) == 0x04)
    printf("3 - registre\n");
  else if (tmp == 0x08)
    printf("3 - direct\n");
  else if (tmp == 0x0C)
    printf("3 - indirect\n");
}
