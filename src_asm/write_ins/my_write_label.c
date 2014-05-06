/*
** my_write_label.c for my_write_label in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 21:23:54 2014 Antoine Plaskowski
** Last update Tue Apr  8 16:58:01 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"
#include	"op.h"

static int	my_found_label_in_ins(t_ins *ins, char *label)
{
  int		j;

  j = 0;
  while (ins->label[j] != NULL)
    if (my_strcmp(label, ins->label[j++]) == 0)
      return (0);
  return (1);
}

static int	my_found_label_prev(t_ins *ins, char *label)
{
  int		i;

  if (my_found_label_in_ins(ins, label) == 0)
    return (0);
  ins = ins->prev;
  i = 0;
  while (ins != NULL)
    {
      i -= ins->octect;
      if (my_found_label_in_ins(ins, label) == 0)
	return (i);
      ins = ins->prev;
    }
  return (1);
}

static int	my_found_label_next(t_ins *ins, char *label)
{
  int		i;

  i = 0;
  while (ins != NULL)
    {
      if (my_found_label_in_ins(ins, label) == 0)
	return (i);
      i += ins->octect;
      ins = ins->next;
    }
  return (-1);
}

int		my_write_label(t_ins *ins, int i, int fd, int special)
{
  int		label;

  if (ins == NULL)
    return (1);
  if ((label = my_found_label_prev(ins, ins->arg[i].arg)) == 1 &&
      (label = my_found_label_next(ins, ins->arg[i].arg)) == -1)
    return (my_put_error_line(ins->line_number,
			      ins->arg[i].arg,
			      " : This label is unfound !\n"));
  if (label / IDX_MOD && (ins->ins < 12 || ins->ins > 14))
    my_put_error_line(ins->line_number, ins->arg[i].arg,
		      "warning IDX_MOD, ce label va trop loin\n");
  if (special || ins->arg[i].type & T_IND)
    {
      if (my_write_oct(&label, IND_SIZE, fd))
	return (my_put_error("can't write in the file\n"));
    }
  else
    {
      if (my_write_oct(&label, DIR_SIZE, fd))
	return (my_put_error("can't write in the file\n"));
    }
  return (0);
}
