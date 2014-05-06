/*
** my_parse_arg_special.c for my_parse_arg_special in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 09:42:35 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:16:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

static int	my_check_type(t_arg *arg, char *mem, int tmp_pc)
{
  if (arg->type == T_REG)
    {
      arg->arg = my_read_oct_modulo(mem, tmp_pc, 1) - 1;
      tmp_pc++;
    }
  else
    {
      arg->arg = my_read_oct_modulo(mem, tmp_pc, IND_SIZE);
      tmp_pc += IND_SIZE;
      arg->type = T_IND;
    }
  return (tmp_pc);
}

int		my_parse_arg_special(t_arg *arg, char *mem, int opcode, int pc)
{
  int		i;
  int		tmp_pc;

  if (arg == NULL || mem == NULL || opcode < 0 || opcode > 15)
    return (-1);
  tmp_pc = pc + 2;
  i = 0;
  while (i < MAX_ARGS_NUMBER && i < op_tab[opcode].nbr_args)
    {
      arg[i].type = my_give_type_codage(mem[(pc + 1) % MEM_SIZE], i);
      if ((arg[i].type & op_tab[opcode].type[i]) == 0)
	return (-1);
      if ((tmp_pc = my_check_type(&arg[i++], mem, tmp_pc)) == -1)
	return (-1);
    }
  return (tmp_pc);
}
