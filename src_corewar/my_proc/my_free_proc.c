/*
** my_free_proc.c for my_free_proc in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_proc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 03:17:57 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:18:54 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

void		my_free_proc(t_proc *proc)
{
  t_proc	*tmp;

  proc = my_first_elem_proc(proc);
  while (proc != NULL)
    {
      tmp = proc;
      proc = proc->next;
      free(tmp);
    }
}
