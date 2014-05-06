/*
** my_new_proc.c for my_new_proc in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 00:58:35 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:42:22 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

t_proc		*my_new_proc(void)
{
  t_proc	*proc;

  if ((proc = my_calloc(sizeof(t_proc))) == NULL)
    return (NULL);
  proc->x_wait = -1;
  return (proc);
}
