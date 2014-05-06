/*
** my_write_ins.c for my_write_ins in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 25 13:43:48 2014 Antoine Plaskowski
** Last update Sun Apr 13 03:32:41 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_de_asm.h"
#include	"my_str.h"
#include	"op.h"

static int	(*g_fct_write[16])(header_t *header, char *champ, int i, int fd) =
{
  &my_write_5,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_3,
  &my_write_special,
  &my_write_special,
  &my_write_3,
  &my_write_normal,
  &my_write_special,
  &my_write_3,
  &my_write_normal
};

int		my_write_ins(header_t *header, char *champ, int fd)
{
  int		i;

  if (header == NULL || champ == NULL)
    return (my_put_error("internal error\n"));
  i = 0;
  while (i < header->prog_size)
    {
      if (champ[i] >= 1 && champ[i] <= 16)
	{
	  if (my_putchar('\t', fd) ||
	      my_putstr(op_tab[champ[i] - 1].mnemonique, fd) ||
	      my_putchar(' ', fd))
	    return (1);
	  if ((i = g_fct_write[champ[i] - 1](header, champ, i, fd)) < 0)
	    return (1);
	  if (my_putchar('\n', fd))
	    return (1);
	}
      else
	{
	  my_putstr("instruction unknown\n", 2);
	  i++;
	}
    }
  return (0);
}
