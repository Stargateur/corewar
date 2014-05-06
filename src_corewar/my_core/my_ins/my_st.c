/*
** my_st.c for my_st in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core/my_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 08:52:25 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:25:57 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

int		my_st(t_vm *vm, t_proc *proc, int opcode)
{
  t_arg		arg[MAX_ARGS_NUMBER];
  int		pc;

  my_putstr("st\n", 1);
  if (vm == NULL || proc == NULL)
    return (1);
  if ((pc = my_parse_arg(arg, vm->mem, opcode, proc->pc)) == -1)
    return (1);
  if (my_load_in_mem(arg, proc, vm->mem, opcode))
    return (1);
  if (arg[1].type == T_REG)
    proc->reg[arg[1].arg] = arg[0].value;
  else
    my_put_oct_modulo(vm->mem, proc->pc + arg[1].arg, arg[0].value, REG_SIZE);
  proc->pc = pc % MEM_SIZE;
  return (0);
}
