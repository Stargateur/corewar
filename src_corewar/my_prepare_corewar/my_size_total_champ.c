/*
** my_size_total_champ.c for my_size_total_champ in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_prepare_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 05:18:55 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:09:09 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

int		my_size_total_champ(t_champ *champ)
{
  int		size_total;

  champ = my_first_elem_champ(champ);
  size_total = 0;
  while (champ != NULL)
    {
      size_total += champ->head.prog_size;
      champ = champ->next;
    }
  return (size_total);
}
