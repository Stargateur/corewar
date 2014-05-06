/*
** my_write_normal.c for my_write_normal in /home/plasko_a/rendu/CPE_2014_corewar/src_asm/write_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 17:55:13 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:23:34 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_asm.h"
#include	"my_str.h"

int		my_write_normal(t_ins *ins, int fd)
{
  int		i;

  if (ins == NULL)
    return (my_put_error("internal error\n"));
  if (write(fd, &ins->octect_codage, 1) != 1)
    return (my_put_error("can't write in the file\n"));
  i = 0;
  while (i < MAX_ARGS_NUMBER)
    {
      if (ins->arg[i].type == T_REG && my_write_registre(ins, i, fd))
	return (1);
      else if (ins->arg[i].type == T_IND && my_write_indirect(ins, i, fd))
	return (1);
      else if (ins->arg[i].type == T_DIR && my_write_direct(ins, i, fd))
	return (1);
      else if (ins->arg[i].type & T_LAB && my_write_label(ins, i, fd, 0))
	return (1);
      i++;
    }
  return (0);
}
