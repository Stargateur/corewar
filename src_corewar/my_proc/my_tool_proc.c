/*
** my_tool_proc.c for my_tool_proc in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_proc
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 06:50:12 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:55:12 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

t_proc		*my_first_elem_proc(t_proc *proc)
{
  if (proc != NULL)
    while (proc->prev)
      proc = proc->prev;
  return (proc);
}

t_proc		*my_last_elem_proc(t_proc *proc)
{
  if (proc != NULL)
    while (proc->next)
      proc = proc->next;
  return (proc);
}

int		my_len_proc(t_proc *proc)
{
  int		i;

  proc = my_first_elem_proc(proc);
  i = 0;
  while (proc != NULL)
    {
      i++;
      proc = proc->next;
    }
  return (i);
}
