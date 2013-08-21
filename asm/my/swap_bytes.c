/*
** swap_bytes.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Tue Dec 11 15:55:02 2012 julien regnier
** Last update Tue Dec 11 15:57:08 2012 julien regnier
*/

void		swap_bytes(char *bytes, int size)
{
  unsigned char	low;
  unsigned char	high;
  char		temp;

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
