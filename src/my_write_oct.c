/*
** my_write_oct.c for my_write_oct in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Mar 20 19:06:16 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:22:37 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"

int		my_write_oct(void *data, int octect, int fd)
{
  if (data == NULL)
    return (1);
  my_rev_oct(data, octect);
  if (write(fd, data, octect) != octect)
    return (1);
  my_rev_oct(data, octect);
  return (0);
}
