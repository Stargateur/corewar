/*
** my_putchar.c for putchar in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct 21 10:46:02 2013 Antoine Plaskowski
** Last update Tue Mar 25 17:12:42 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	"my_str.h"

int		my_putchar(const char c, const int fd)
{
  if (write(fd, &c, 1) != 1)
    {
      write(2, "Sorry write fail\n", my_strlen("Sorry write fail\n"));
      return (1);
    }
  return (0);
}
