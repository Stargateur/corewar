/*
** my_size_special.c for my_size_special in /home/plasko_a/rendu/CPE_2014_corewar/src_asm/size_ins
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Mar 20 14:51:48 2014 Antoine Plaskowski
** Last update Sat Apr 12 01:40:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"

int		my_size_special(t_ins *ins)
{
  int		size;
  int		i;

  if (ins == NULL)
    return (0);
  size = 2;
  i = 0;
  while (i < MAX_ARGS_NUMBER)
    {
      if (ins->arg[i].type & T_REG)
	size += 1;
      else if (ins->arg[i].type & T_DIR || ins->arg[i].type & T_IND)
	size += IND_SIZE;
      i++;
    }
  my_set_octect_codage(ins);
  return (size);
}
