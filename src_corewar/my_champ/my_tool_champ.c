/*
** my_tool_champ.c for my_tool_champ in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 02:22:52 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:11:15 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

t_champ		*my_first_elem_champ(t_champ *champ)
{
  if (champ != NULL)
    while (champ->prev != NULL)
      champ = champ->prev;
  return (champ);
}

t_champ		*my_last_elem_champ(t_champ *champ)
{
  if (champ != NULL)
    while (champ->next != NULL)
      champ = champ->next;
  return (champ);
}

int		my_len_champ(t_champ *champ)
{
  int		i;

  champ = my_first_elem_champ(champ);
  i = 0;
  while (champ != NULL)
    {
      i++;
      champ = champ->next;
    }
  return (i);
}
