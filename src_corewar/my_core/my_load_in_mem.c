/*
** my_load_in_mem.c for my_load_in_mem in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 13:51:50 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:11:24 2014 Antoine Plaskowski
*/

#include        <stdlib.h>
#include        "my_corewar.h"
#include        "my_str.h"
#include        "op.h"

int             my_load_in_mem(t_arg *arg, t_proc *proc, char *mem, int opcode)
{
  int           i;
  int		tmp;

  if (arg == NULL || proc == NULL || mem == NULL)
    return (1);
  i = 0;
  while (i < MAX_ARGS_NUMBER && i < op_tab[opcode].nbr_args)
    {
      if (arg[i].type == T_REG)
        {
	  if (arg[i].arg < 0 || arg[i].arg >= REG_NUMBER)
	    return (1);
	  arg[i].value = proc->reg[arg[i].arg];
	}
      else
	{
	  if (opcode < 12 || opcode > 14)
	    tmp = proc->pc + arg[i].arg % IDX_MOD + MEM_SIZE;
	  else
	    tmp = proc->pc + arg[i].arg + MEM_SIZE;
	  arg[i].value = my_read_oct_modulo(mem, tmp % MEM_SIZE, REG_SIZE);
	}
      i++;
    }
  return (0);
}
