/*
** my_lfork.c for my_lfork in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core/my_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 08:52:25 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:23:15 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

int		my_lfork(t_vm *vm, t_proc *proc, int opcode)
{
  t_proc	*new_proc;
  int		new_pc;

  my_putstr("lfork\n", 1);
  (void)opcode;
  if (vm == NULL || proc == NULL)
    return (1);
  new_pc = my_read_oct_modulo(vm->mem, proc->pc + 1, IND_SIZE);
  if ((new_proc = my_cpy_proc(proc)) == NULL)
    return (1);
  new_proc->pc = (proc->pc + new_pc + MEM_SIZE) % MEM_SIZE;
  new_proc->x_wait = op_tab[opcode].nbr_cycles;
  proc->pc = (proc->pc + 3) % MEM_SIZE;
  if (my_put_proc(proc, new_proc) == NULL)
    return (1);
  proc->carry = !new_pc;
  return (0);
}
