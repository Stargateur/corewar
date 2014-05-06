/*
** my_lldi.c for my_lldi in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core/my_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 08:52:25 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:23:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

int		my_lldi(t_vm *vm, t_proc *proc, int opcode)
{
  t_arg		arg[MAX_ARGS_NUMBER];
  int		pc;
  int		tmp;

  my_putstr("lldi\n", 1);
  if (vm == NULL || proc == NULL)
    return (1);
  if ((pc = my_parse_arg_special(arg, vm->mem, opcode, proc->pc)) == -1)
    return (1);
  if (my_load_in_mem(arg, proc, vm->mem, opcode))
    return (1);
  tmp = proc->pc;
  tmp += my_value_if_reg(&arg[0]);
  tmp += my_value_if_reg(&arg[1]);
  proc->reg[arg[2].arg] = my_read_oct_modulo(vm->mem, tmp, REG_SIZE);
  proc->carry = !proc->reg[arg[2].arg];
  proc->pc = pc % MEM_SIZE;
  return (0);
}
