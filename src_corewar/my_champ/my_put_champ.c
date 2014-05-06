/*
** my_put_champ.c for my_put_champ in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 01:04:48 2014 Antoine Plaskowski
** Last update Sun Apr 13 06:42:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

t_champ		*my_put_champ(t_champ *old, t_champ *champ)
{
  old = my_last_elem_champ(old);
  if (old != NULL)
    {
      old->next = champ;
      if (champ != NULL)
	champ->prev = old;
    }
  else
    old = champ;
  return (my_first_elem_champ(old));
}
