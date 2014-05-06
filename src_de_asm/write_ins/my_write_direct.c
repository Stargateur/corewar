/*
** my_write_direct.c for my_write_direct in /home/plasko_a/rendu/CPE_2014_corewar/src_de_asm/write_ins
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Mar 25 16:09:54 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:29:05 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"op.h"

int		my_write_direct(header_t *header, char *champ, int i, int fd)
{
  int		direct;

  if (header == NULL || champ == NULL ||
      i < 0 ||i + DIR_SIZE - 1 > header->prog_size)
    return (my_put_error("invalid champion\n") * -1);
  direct = my_read_oct(champ + i, DIR_SIZE);
  if (my_putchar('%', fd) || my_putnbr(direct, fd))
    return (-1);
  return (DIR_SIZE);
}
