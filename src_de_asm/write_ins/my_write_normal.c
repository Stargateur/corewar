/*
** my_write_normal.c for my_write_normal in /home/plasko_a/rendu/CPE_2014_corewar/src_asm/write_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 17:55:13 2014 Antoine Plaskowski
** Last update Thu Apr  3 15:53:00 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_de_asm.h"
#include	"my_str.h"

static int	my_write(header_t *header, char *champ, int i, int fd)
{
  int		tab[MAX_ARGS_NUMBER];
  int		j;
  int		status;

  if (my_check_octect_codage(champ[i - 2] - 1, champ[i - 1], tab))
    return (-1);
  j = 0;
  while (j < MAX_ARGS_NUMBER && tab[j] != 0)
    {
      status = 0;
      if (tab[j] == T_REG)
	status = my_write_registre(header, champ, i, fd);
      else if (tab[j] == T_IND)
	status = my_write_indirect(header, champ, i, fd);
      else if (tab[j] == T_DIR)
	status = my_write_direct(header, champ, i, fd);
      if (status < 1)
	return (-1);
      i += status;
      j++;
      if (j < MAX_ARGS_NUMBER && tab[j] != 0)
	if (my_putstr(", ", fd))
	  return (-1);
    }
  return (i);
}

int		my_write_normal(header_t *header, char *champ, int i, int fd)
{
  if (header == NULL || champ == NULL || i < 0 || i + 1 >= header->prog_size)
    return (-1);
  return (my_write(header, champ, i + 2, fd));
}
