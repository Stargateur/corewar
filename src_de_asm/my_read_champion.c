/*
** my_read_champion.c for my_read_champion in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 24 20:02:35 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:25:17 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"
#include	"op.h"

char		*my_read_champion(header_t *header, int fd)
{
  char		*champ;
  char		test;

  if (header == NULL)
    return (my_put_error_null("internal error\n"));
  if ((champ = my_malloc(sizeof(char) * header->prog_size)) == NULL)
    return (NULL);
  if (read(fd, champ, header->prog_size) != header->prog_size)
    return (my_put_error_null("error prog_size if not corect\n"));
  if (read(fd, &test, 1) != 0)
    return (my_put_error_null("error prog_size if not corect\n"));
  return (champ);
}
