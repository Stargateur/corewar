/*
** my_free_champ.c for my_free_champ in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_champ
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 07:14:43 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:19:21 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

void		my_free_champ(t_champ *champ)
{
  t_champ	*tmp;

  champ = my_first_elem_champ(champ);
  while (champ != NULL)
    {
      free(champ->path);
      free(champ->prog);
      tmp = champ;
      champ = champ->next;
      free(tmp);
    }
}
