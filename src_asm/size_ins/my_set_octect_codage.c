/*
** my_set_octect_codage.c for my_set_octect_codage in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 24 18:57:33 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:21:22 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"

int		my_set_octect_codage(t_ins *ins)
{
  int		i;

  if (ins == NULL)
    return (my_put_error("internal error\n"));
  ins->octect_codage = 0;
  i = 0;
  while (i < MAX_ARGS_NUMBER)
    {
      if (ins->arg[i].type & T_REG)
        ins->octect_codage += 1 << (6 - i * 2);
      else if (ins->arg[i].type & T_IND)
        {
          ins->octect_codage += 1 << (7 - i * 2);
          ins->octect_codage += 1 << (6 - i * 2);
        }
      else if (ins->arg[i].type & T_DIR)
        ins->octect_codage += 1 << (7 - i * 2);
      i++;
    }
  return (0);
}
