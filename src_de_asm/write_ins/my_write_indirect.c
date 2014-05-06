/*
** my_write_indirect.c for my_write_indirect in /home/plasko_a/rendu/CPE_2014_corewar/src_de_asm/write_ins
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Mar 25 16:09:54 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:29:20 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"op.h"

int		my_write_indirect(header_t *header, char *champ, int i, int fd)
{
  int		indirect;

  if (header == NULL || champ == NULL ||
      i < 0 || i + IND_SIZE - 1 > header->prog_size)
    return (my_put_error("invalid champion\n") * -1);
  indirect = my_read_oct(champ + i, IND_SIZE);
  if (my_putnbr(indirect, fd))
    return (-1);
  return (IND_SIZE);
}
