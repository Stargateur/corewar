/*
** my_delete_proc.c for my_sup in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_proc
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 03:09:23 2014 Antoine Plaskowski
** Last update Sun Apr 13 15:51:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

t_proc		*my_sup_proc(t_proc *old)
{
  t_proc	*proc;

  proc = NULL;
  if (old != NULL)
    {
      if (old->prev != NULL)
	{
	  proc = old->prev;
	  old->prev->next = old->next;
	}
      if (old->next != NULL)
	{
	  proc = old->next;
	  old->next->prev = old->prev;
	}
      free(old);
    }
  return (proc);
}
