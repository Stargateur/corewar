/*
** my_getnbr.c for my_getnbr in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 13:27:41 2013 Antoine Plaskowski
** Last update Thu Apr 10 17:47:15 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

static int	my_check_overflow(const char *str, int sign)
{
  int		i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  if (i > my_strlen("2147483647"))
    return (my_put_error("Warning overflow direct\n"));
  else if (i == my_strlen("2147483647"))
    {
      if (sign > 0)
	{
	  if (my_strncmp(str, "2147483647", i) > 0)
	    return (my_put_error("Warning overflow direct\n"));
	}
      else
	{
	  if (my_strncmp(str, "2147483648", i) > 0)
	    return (my_put_error("Warning overflow direct\n"));
	}
    }
  return (0);
}

int		my_getnbr(const char *str)
{
  int		sign;
  int		nbr;

  if (str == NULL)
    return (0);
  sign = 1;
  while (*str != '\0' && (*str == '-' || *str == '+'))
    if (*str++ == '-')
      sign *= -1;
  while (*str == '0')
    str++;
  my_check_overflow(str, sign);
  nbr = 0;
  if (sign > 0)
    while (*str >= '0' && *str <= '9')
      nbr = nbr * 10 + (*str++ - '0');
  else
    while (*str >= '0' && *str <= '9')
      nbr = nbr * 10 - (*str++ - '0');
  return (nbr);
}
