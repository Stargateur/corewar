/*
** my_write_header.c for my_write_header in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Mar 24 22:01:12 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:25:45 2014 Antoine Plaskowski
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
  if (my_strlen(header->prog_name))
    if (my_putstr("\t.name \"", fd) || my_putstr(header->prog_name, fd) ||
	my_putstr("\"\n", fd))
      return (1);
  if (my_strlen(header->comment))
    if (my_putstr("\t.comment \"", fd) || my_putstr(header->comment, fd) ||
	my_putstr("\"\n", fd))
      return (1);
  return (0);
}
