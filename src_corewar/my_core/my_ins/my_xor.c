/*
** my_xor.c for my_xor in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core/my_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 08:52:25 2014 Antoine Plaskowski
** Last update Tue May  6 22:39:47 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

int		my_xor(t_vm *vm, t_proc *proc, int opcode)
{
  t_arg		arg[MAX_ARGS_NUMBER];
  int		pc;

  my_putstr("xor", 1);
  if (vm == NULL || proc == NULL)
    return (1);
  if ((pc = my_parse_arg(arg, vm->mem, opcode, proc->pc)) == -1)
    return (1);
  if (my_load_in_mem(arg, proc, vm->mem, opcode))
    return (1);
  proc->reg[arg[2].arg] = arg[0].value ^ arg[1].value;
  proc->carry = !proc->reg[arg[2].arg];
  proc->pc = pc % MEM_SIZE;
  return (0);
}
