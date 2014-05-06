/*
** my_create_proc.c for my_create_proc in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_prepare_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 07:36:41 2014 Antoine Plaskowski
** Last update Sun Apr 13 08:15:41 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

t_proc		*my_init_proc(t_proc *old, int id, int pc)
{
  t_proc	*proc;

  if ((proc = my_new_proc()) == NULL)
    return (NULL);
  proc->id = id;
  proc->pc = pc;
  proc->carry = 0;
  proc->reg[0] = id;
  return (my_put_proc(old, proc));
}

t_proc		*my_create_proc(t_champ *champ)
{
  t_proc	*proc;

  champ = my_first_elem_champ(champ);
  proc = NULL;
  while (champ != NULL)
    {
      if ((proc = my_init_proc(proc, champ->id, champ->pc)) == NULL)
	return (NULL);
      champ = champ->next;
    }
  return (my_first_elem_proc(proc));
}
