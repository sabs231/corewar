/*
** endianness.c for src in /home/chapea_o/travail/corewar/src/src
** 
** Made by olivier chapeau
** Login   <chapea_o@epitech.net>
** 
** Started on  Mon Dec 03 17:21:29 2012 olivier chapeau
** Last update Mon Dec 10 14:35:26 2012 sergioandres baezserrano
*/

#include <stdio.h>
#include "endianness.h"

void    swap_bytes(char *bytes, size_t size)
{
  unsigned char       low;
  unsigned char       high;
  char                temp;

  low = 0;
  high = size - 1;
  while (low < high)
  {
    temp = bytes[low];
    bytes[low] = bytes[high];
    bytes[high] = temp;
    low = low + 1;
    high = high - 1;
  }
}

