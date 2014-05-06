/*
** my_core.c for my_core in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 07:31:41 2014 Antoine Plaskowski
** Last update Sun Apr 13 23:10:27 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

static t_proc	*my_kill_them_all(t_proc *proc, int id)
{
  proc = my_first_elem_proc(proc);
  if (proc != NULL)
    {
      while (proc->next != NULL)
	{
	  if (proc->id == id)
	    proc = my_sup_proc(proc);
	  else
	    proc = proc->next;
	  if (proc == NULL)
	    return (NULL);
	}
      if (proc->id == id)
	proc = my_sup_proc(proc);
    }
  return (my_first_elem_proc(proc));
}

static t_proc	*my_kill_proc_not_alive(t_champ *champ, t_proc *proc)
{
  champ = my_first_elem_champ(champ);
  while (champ != NULL)
    {
      if (champ->alive == 0)
	proc = my_kill_them_all(proc, champ->id);
      champ = champ->next;
    }
  return (proc);
}

static int	my_nbr_champ_alive(t_champ *champ)
{
  int		i;

  i = 0;
  champ = my_first_elem_champ(champ);
  while (champ != NULL)
    {
      if (champ->alive)
	{
	  champ->alive = 0;
	  i++;
	}
      champ = champ->next;
    }
  return (i);
}

static int	my_winner_is(t_champ *champ, int id_last_live)
{
  champ = my_first_elem_champ(champ);
  while (champ != NULL)
    {
      if (champ->id == id_last_live)
	{
	  my_putstr("The winner is ", 1);
	  my_putstr(champ->head.prog_name, 1);
	  my_putstr(" ! id : ", 1);
	  my_putnbr(champ->id, 1);
	  my_putchar('\n', 1);
	  return (0);
	}
      champ = champ->next;
    }
  my_putstr("NO ONE IS LIVING ?!\n", 1);
  my_putstr("SEEMS LIKE WE HAVE A TEAM OF JEAM MICHEL PAS CHAMPION !\n", 1);
  return (1);
}

int		my_core(t_vm *vm)
{
  int		x_current;
  int		x_total;

  x_total = 0;
  while (42)
    {
      x_current = 0;
      while (x_current++ < vm->x_die)
	{
	  if (vm->dump && x_total++ > vm->x_dump)
	    {
	      my_dump_memory(vm->mem);
	      return (0);
	    }
	  my_do_one_cycle(vm);
	}
      if ((vm->proc = my_kill_proc_not_alive(vm->champ, vm->proc)) == NULL)
	return (my_winner_is(vm->champ, vm->id_last_live));
      if (my_nbr_champ_alive(vm->champ) <= 1)
	return (my_winner_is(vm->champ, vm->id_last_live));
    }
  return (1);
}
