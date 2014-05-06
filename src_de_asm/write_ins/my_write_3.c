/*
** my_write_3.c for my_write_3 in /home/plasko_a/rendu/CPE_2014_corewar/src_asm/write_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 17:55:13 2014 Antoine Plaskowski
** Last update Thu Apr  3 15:54:53 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_de_asm.h"
#include	"my_str.h"

int		my_write_3(header_t *header, char *champ, int i, int fd)
{
  int		status;

  if (header == NULL || champ == NULL)
    return (-1);
  if (my_putstr("%", fd))
      return (-1);
  i++;
  status = my_write_indirect(header, champ, i, fd);
  if (status == -1)
    return (-1);
  i += status;
  return (i);
}
