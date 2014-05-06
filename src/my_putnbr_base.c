/*
** my_putnbr_base.c for my_putnbr_base in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_15
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Oct  8 16:45:05 2013 Antoine Plaskowski
** Last update Wed Mar 26 21:57:51 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_putnbr_base(int nb, const char *base, const int fd)
{
  int		len;

  if ((len = my_strlen(base)) < 2)
    return (1);
  if (nb / len != 0)
    {
      if (my_putnbr_base(nb / len, base, fd))
	return (1);
    }
  else if (nb < 0)
    {
      if (my_putchar('-', fd))
	return (1);
    }
  if ((nb %= len) < 0)
    nb *= -1;
  if (my_putchar(base[nb], fd))
    return (1);
  return (0);
}
