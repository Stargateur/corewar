/*
** my_define_id_champ.c for my_define_id_champ in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_prepare_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 05:11:40 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:21:45 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

static int	my_id_is_not_dispo(t_champ *champ, int id)
{
  while (champ != NULL)
    {
      if (champ->id == id)
	return (1);
      champ = champ->next;
    }
  return (0);
}

int		my_define_id_champ(t_champ *champ, int id)
{
  int		id_auto;

  champ = my_first_elem_champ(champ);
  id_auto = 1;
  if (id == -1)
    {
      while (my_id_is_not_dispo(champ, id_auto))
	id_auto++;
      return (id_auto);
    }
  else if (my_id_is_not_dispo(champ, id))
    return (my_put_error("You have put some same id in option\n") * -1);
  return (id);
}
