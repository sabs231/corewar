/*
** my_getnbr.c for my in /home/regnie_j/corewar/my
** 
** Made by julien regnier
** Login   <regnie_j@epitech.net>
** 
** Started on  Tue Oct  9 18:30:05 2012 julien regnier
** Last update Fri Dec 14 20:02:40 2012 julien regnier
*/

int	my_getnbr(char *str)
{
  int	sign;
  int	nb;

  sign = 1;
  nb = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign = sign * -1;
      str = str + 1;
    }
  while (*str >= '0' && *str <= '9')
    {
      nb = nb * 10;
      nb = nb + (*str - '0');
      str = str + 1;
    }
  return (nb * sign);
}
