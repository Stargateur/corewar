/*
** my_write_registre.c for my_write_registre in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Mar 20 21:23:54 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:23:45 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"

int		my_write_registre(t_ins *ins, int i, int fd)
{
  int		registre;

  if (ins == NULL)
    return (my_put_error("internal error\n"));
  registre = my_getnbr(ins->arg[i].arg);
  if (my_write_oct(&registre, 1, fd))
    return (my_put_error("can't write in the file\n"));
  return (0);
}
