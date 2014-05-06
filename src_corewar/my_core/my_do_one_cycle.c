/*
** my_do_one_cycle.c for my_do_one_cycle in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 08:21:32 2014 Antoine Plaskowski
** Last update Sun Apr 13 20:07:16 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

static int	(*g_fct_ins[])(t_vm *vm, t_proc *proc, int opcode) =
{
  &my_live,
  &my_ld,
  &my_st,
  &my_add,
  &my_sub,
  &my_and,
  &my_or,
  &my_xor,
  &my_zjmp,
  &my_ldi,
  &my_sti,
  &my_fork,
  &my_lld,
  &my_lldi,
  &my_lfork,
  &my_aff
};
  
int		my_do_one_cycle(t_vm *vm)
{
  t_proc	*proc;
  int		opcode;

  proc = my_first_elem_proc(vm->proc);
  while (proc != NULL)
    {
      if (proc->x_wait > 0)
	proc->x_wait--;
      else
	{
	  opcode = vm->mem[proc->pc % MEM_SIZE] - 1;
	  if (opcode >= 0 && opcode <= 15 &&
	      g_fct_ins[opcode](vm, proc, opcode) == 0)
	    proc->x_wait = op_tab[opcode].nbr_cycles;
	  else
	    proc->pc++;
	}
      proc = proc->next;
    }
  return (0);
}
