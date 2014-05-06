/*
** my_write_indirect.c for my_write_indirect in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 21:23:54 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:22:52 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"
#include	"op.h"

int		my_write_indirect(t_ins *ins, int i, int fd)
{
  int		indirect;

  if (ins == NULL)
    return (my_put_error("internal error\n"));
  indirect = my_getnbr(ins->arg[i].arg);
  if (indirect / IDX_MOD && (ins->ins < 12 || ins->ins > 14))
    my_put_error_line(ins->line_number, ins->arg[i].arg,
		      "warning IDX_MOD cet indirect va trop loin\n");
  if (my_write_oct(&indirect, IND_SIZE, fd))
    return (my_put_error("can't write int the file\n"));
  return (0);
}
