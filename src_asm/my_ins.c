/*
** my_ins.c for my_ins in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Mar 10 17:56:36 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:13:46 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_asm.h"
#include	"my_str.h"
#include	"my_tool_tab.h"

t_ins		*my_new_ins(void)
{
  t_ins		*new;
  int		i;

  if ((new = my_malloc(sizeof(t_ins))) == NULL)
    return (NULL);
  new->prev = NULL;
  new->label = NULL;
  new->ins = -1;
  i = 0;
  while (i < MAX_ARGS_NUMBER)
    {
      new->arg[i].type = 0;
      new->arg[i++].arg = NULL;
    }
  new->octect = 0;
  new->octect_codage = 0;
  new->line_number = 0;
  new->next = NULL;
  return (new);
}

t_ins		*my_put_ins(t_ins *old, t_ins *ins)
{
  ins->next = NULL;
  if (old == NULL)
    ins->prev = NULL;
  else
    {
      while (old->next != NULL)
	old = old->next;
      ins->prev = old;
      old->next = ins;
    }
  return (ins);
}

void		my_free_ins(t_ins *ins)
{
  t_ins		*tmp;
  int		i;

  if (ins != NULL)
    {
      while (ins->prev != NULL)
	ins = ins->prev;
      while (ins != NULL)
	{
	  my_free_tab(ins->label);
	  i = 0;
	  while (i < MAX_ARGS_NUMBER)
	    free(ins->arg[i++].arg);
	  tmp = ins;
	  ins = ins->next;
	  free(tmp);
	}
    }
}

int		my_check_ins(t_ins *ins, char *str)
{
  if (ins != NULL)
    {
      if (ins->ins != -1)
	return (0);
      else
	if (*str != '\0')
	  return (my_put_error("instruction unknown\n"));
      if (ins->label != NULL)
	if (ins->label[0] != NULL)
	  return (0);
    }
  return (my_put_error("You can't pass here wtf !\n"));
}
