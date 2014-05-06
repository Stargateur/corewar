/*
** my_putstr.c for my_putstr in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 10:36:52 2013 Antoine Plaskowski
** Last update Tue Mar 25 15:02:12 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"

int		my_putstr(const char *str, const int fd)
{
  int		len;

  if (str == NULL)
    return (1);
  len = my_strlen(str);
  if (write(fd, str, len) != len)
    {
      write(2, "Sorry write fail\n", my_strlen("Sorry write fail\n"));
      return (1);
    }
  return (0);
}
