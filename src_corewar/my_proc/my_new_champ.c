/*
** my_new_champ.c for my_new_champ in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 01:01:04 2014 Antoine Plaskowski
** Last update Sun Apr 13 06:40:21 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

t_champ          *my_new_champ(void)
{
  t_champ        *champ;

  if ((champ = my_calloc(sizeof(t_champ))) == NULL)
    return (NULL);
  champ->alive = 1;
  return (champ);
}
