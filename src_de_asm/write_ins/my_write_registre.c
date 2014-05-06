/*
** my_write_registre.c for my_write_registre in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 21:23:54 2014 Antoine Plaskowski
** Last update Sat Apr 12 01:53:02 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"op.h"

int		my_write_registre(header_t *header, char *champ, int i, int fd)
{
  if (header == NULL || champ == NULL || i < 0 || i > header->prog_size)
    return (my_put_error("Champion invalide\n") * -1);
  if (champ[i] < 1 || champ[i] > REG_NUMBER)
    return (my_put_error("numero de registre invalide\n") * -1);
  if (my_putchar('r', fd) || my_putnbr(champ[i], fd))
    return (-1);
  return (1);
}
