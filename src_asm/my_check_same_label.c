/*
** my_check_same_label.c for my_check_same_label in /home/plasko_a/rendu/corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr  6 01:52:32 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:14:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"

static int	my_check_all_label(t_ins *ins, char *label)
{
  int		i;

  while (ins != NULL)
    {
      i = 0;
      while (ins->label != NULL && ins->label[i] != NULL)
	{
	  if (my_strcmp(ins->label[i], label) == 0)
	    return (1);
	  i++;
	}
      ins = ins->next;
    }
  return (0);
}

int		my_check_same_label(t_ins *ins)
{
  int		i;

  while (ins != NULL)
    {
      i = 0;
      while (ins->label != NULL && ins->label[i] != NULL)
	{
	  if (my_check_all_label(ins->next, ins->label[i]))
	    return (my_put_error_line(ins->line_number, ins->label[i],
				      "This label already exist\n"));
	  i++;
	}
      ins = ins->next;
    }
  return (0);
}
