/*
** my_put_error.c for my_put_error in /home/plasko_a/rendu/corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Mar 26 17:11:26 2014 Antoine Plaskowski
** Last update Sun Apr  6 02:06:43 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_put_error(char *str)
{
  my_putstr(str, 2);
  return (1);
}

void		*my_put_error_null(char *str)
{
  my_putstr(str, 2);
  return (NULL);
}

int		my_put_error_line(int i, char *str, char *error)
{
  my_putstr("line ", 2);
  my_putnbr(i, 2);
  my_putstr(" : ", 2);
  my_putstr(str, 2);
  my_putstr(" : ", 2);
  my_putstr(error, 2);
  return (1);
}

void		*my_put_error_line_null(int i, char *str, char *error)
{
  my_putstr("line ", 2);
  my_putnbr(i, 2);
  my_putstr(" : ", 2);
  my_putstr(str, 2);
  my_putstr(" : ", 2);
  my_putstr(error, 2);
  return (NULL);
}
