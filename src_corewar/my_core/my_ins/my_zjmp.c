/*
** my_zjmp.c for my_zjmp in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core/my_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 08:52:25 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:31:38 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

int		my_zjmp(t_vm *vm, t_proc *proc, int opcode)
{
  int           new_pc;

  my_putstr("zjmp\n", 1);
  (void)opcode;
  if (vm == NULL || proc == NULL)
    return (1);
  if (proc->carry)
    {
      new_pc = my_read_oct_modulo(vm->mem, proc->pc + 1, IND_SIZE);
      proc->pc = (proc->pc + new_pc % IDX_MOD + MEM_SIZE) % MEM_SIZE;
      return (0);
    }
  return (1);
}
