/*
** my_write_special.c for my_write_special in /home/plasko_a/rendu/CPE_2014_corewar/src_asm/write_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 17:55:13 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:23:55 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_asm.h"
#include	"my_str.h"

int		my_write_special(t_ins *ins, int fd)
{
  int		i;

  if (ins == NULL)
    return (my_put_error("internal error"));
  if (write(fd, &ins->octect_codage, 1) != 1)
    return (my_put_error("can't write the cor sorry !\n"));
  i = 0;
  while (i < MAX_ARGS_NUMBER)
    {
      if (ins->arg[i].type == T_REG && my_write_registre(ins, i, fd))
	return (1);
      else if ((ins->arg[i].type == T_IND || ins->arg[i].type == T_DIR) &&
	       my_write_indirect(ins, i, fd))
	return (1);
      else if (ins->arg[i].type & T_LAB && my_write_label(ins, i, fd, 1))
	return (1);
      i++;
    }
  return (0);
}
