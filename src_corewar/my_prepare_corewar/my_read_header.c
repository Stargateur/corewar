/*
** my_read_header.c for my_read_header in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 01:14:31 2014 Antoine Plaskowski
** Last update Sun Apr 13 03:06:04 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"
#include	"op.h"

int		my_read_header(header_t *header, int fd)
{
  if (header == NULL)
    return (1);
  if (read(fd, header, sizeof(header_t)) != sizeof(header_t))
    return (my_put_error("header incorect\n"));
  my_rev_oct(&(header->magic), sizeof(header->magic));
  my_rev_oct(&(header->prog_size), sizeof(header->prog_size));
  header->prog_name[PROG_NAME_LENGTH] = '\0';
  header->comment[COMMENT_LENGTH] = '\0';
  if (header->magic != COREWAR_EXEC_MAGIC)
    return (my_put_error("magic number non valide\n"));
  return (0);
}
