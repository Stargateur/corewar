/*
** my_write_header.c for my_write_header in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 17:42:29 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:20:31 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_asm.h"
#include	"my_str.h"
#include	"op.h"

int		my_write_header(header_t *header, int fd)
{
  if (header == NULL)
    return (my_put_error("internal error\n"));
  my_rev_oct(&header->magic, sizeof(header->magic));
  my_rev_oct(&header->prog_size, sizeof(header->prog_size));
  if (write(fd, header, sizeof(header_t)) != sizeof(header_t))
    return (my_put_error("can't write the cor sorry !\n"));
  my_rev_oct(&header->magic, sizeof(header->magic));
  my_rev_oct(&header->prog_size, sizeof(header->prog_size));
  return (0);
}
