/*
** my_put_proc.c for my_put_proc in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_proc
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 06:21:26 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:23:03 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

t_proc		*my_put_proc(t_proc *old, t_proc *proc)
{
  old = my_last_elem_proc(old);
  if (old != NULL)
    {
      old->next = proc;
      if (proc != NULL)
	proc->prev = old;
    }
  else
    old = proc;
  return (my_first_elem_proc(old));
}
