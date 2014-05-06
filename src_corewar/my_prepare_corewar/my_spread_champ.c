/*
** my_spread_champ.c for my_spread_champ in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_prepare_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 06:37:53 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:12:48 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_corewar.h"

int		my_put_champ_in_mem(t_champ *champ, char *mem, int i)
{
  int           j;

  j = 0;
  while (j < champ->head.prog_size)
    mem[i++ % MEM_SIZE] = champ->prog[j++];
  return (0);
}

int             my_spread_champ(t_champ *champ, char *mem)
{
  int		gap;
  int		i;

  gap = (MEM_SIZE - my_size_total_champ(champ)) / my_len_champ(champ);
  i = 0;
  while (champ != NULL)
    {
      if (champ->pc == -1)
	champ->pc = i;
      my_put_champ_in_mem(champ, mem, champ->pc);
      i += gap + champ->head.prog_size;
      champ = champ->next;
    }
  return (0);
}
