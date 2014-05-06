/*
** my_set_size_ins.c for my_set_size_ins in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 11 19:02:44 2014 Antoine Plaskowski
** Last update Wed Apr  9 12:11:16 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"

static int	(*g_fct_size[16])(t_ins *ins) =
{
  &my_size_no_codage,
  &my_size_normal,
  &my_size_normal,
  &my_size_normal,
  &my_size_normal,
  &my_size_normal,
  &my_size_normal,
  &my_size_normal,
  &my_size_special_no_codage,
  &my_size_special,
  &my_size_special,
  &my_size_special_no_codage,
  &my_size_normal,
  &my_size_special,
  &my_size_special_no_codage,
  &my_size_normal,
};

int		my_set_size_ins(t_ins *ins)
{
  while (ins != NULL)
    {
      if (ins->ins != -1)
	ins->octect = g_fct_size[ins->ins](ins);
      ins = ins->next;
    }
  return (0);
}

int		my_size_prog(t_ins *ins)
{
  int		i;

  i = 0;
  while (ins != NULL)
    {
      i += ins->octect;
      ins = ins->next;
    }
  return (i);
}
