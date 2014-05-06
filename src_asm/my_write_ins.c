/*
** my_write_ins.c for my_write_ins in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 20:43:50 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:21:00 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_asm.h"
#include	"my_str.h"

static int	(*g_fct_write[16])(t_ins *ins, int fd) =
{
  &my_write_no_codage,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_normal,
  &my_write_special_no_codage,
  &my_write_special,
  &my_write_special,
  &my_write_special_no_codage,
  &my_write_normal,
  &my_write_special,
  &my_write_special_no_codage,
  &my_write_normal
};

static int	my_write_op_code(char op, int fd)
{
  if (write(fd, &op, sizeof(char)) != sizeof(char))
    return (my_put_error("can't write the file sry !\n"));
  return (0);
}

static int	my_check_exist_ins(t_ins *ins)
{
  while (ins != NULL)
    {
      if (ins->ins != -1)
	return (0);
      ins = ins->next;
    }
  return (1);
}

int		my_write_ins(t_ins *ins, int fd)
{
  if (my_check_exist_ins(ins))
    return (my_put_error("no instruction\n"));
  while (ins != NULL)
    {
      if (ins->ins != -1)
	{
	  if (my_write_op_code(ins->ins + 1, fd))
	    return (1);
	  if (g_fct_write[ins->ins](ins, fd))
	    return (1);
	}
      ins = ins->next;
    }
  return (0);
}
