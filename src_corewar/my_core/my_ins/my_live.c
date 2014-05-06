/*
** my_live.c for my_live in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core/my_ins
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 08:32:31 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:21:52 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

static int	my_set_alive(t_champ *champ, int *id_last_live, int id)
{
  champ = my_first_elem_champ(champ);
  while (champ != NULL)
    {
      if (champ->id == id)
	{
	  champ->alive = 1;
	  *id_last_live = id;
	  my_putstr("le joueur ", 1);
	  my_putstr(champ->head.prog_name, 1);
	  my_putstr(" est en vie ! id : ", 1);
	  my_putnbr(id, 1);
	  my_putchar('\n', 1);
	  return (0);
	}
      champ = champ->next;
    }
  return (1);
}

int		my_live(t_vm *vm, t_proc *proc, int opcode)
{
  int		id;

  my_putstr("live\n", 1);
  (void)opcode;
  if (vm == NULL || proc == NULL)
    return (1);
  id = my_read_oct_modulo(vm->mem, proc->pc + 1, DIR_SIZE);
  vm->nbr_live++;
  if (vm->nbr_live == 30)
    {
      vm->nbr_live = 0;
      vm->x_die -= CYCLE_DELTA;
    }
  proc->pc = (proc->pc + 5) % MEM_SIZE;
  return (my_set_alive(vm->champ, &vm->id_last_live, id));
}
