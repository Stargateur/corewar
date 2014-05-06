/*
** my_put_nbr.c for my_put_nbr in /home/plasko_a/rendu/Piscine-C-Jour_03
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Oct  2 13:24:35 2013 Antoine Plaskowski
** Last update Tue Mar 25 15:29:41 2014 Antoine Plaskowski
*/

#include	"my_str.h"

int		my_putnbr(int nb, const int fd)
{
  if (nb / 10 != 0)
    {
      if (my_putnbr(nb / 10, fd))
	return (1);
    }
  else if (nb < 0)
    {
      if (my_putchar('-', fd))
	return (1);
    }
  if ((nb %= 10) < 0)
    nb *= -1;
  if (my_putchar(nb + '0', fd))
    return (1);
  return (0);
}
