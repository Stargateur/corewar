/*
** my_parse_arg.c for my_parse_arg in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 11 16:10:05 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:18:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"

char		*my_parse_registre(t_ins *ins, char *str, int i)
{
  int		j;
  int		reg;

  ins->arg[i].type = T_REG;
  if ((op_tab[ins->ins].type[i] & T_REG) == 0)
    return (my_put_error_null("wrong type of argument\n"));
  reg = my_getnbr(++str);
  if (reg < 1 || reg > REG_NUMBER)
    return (my_put_error_null("wrong type of argument\n"));
  j = 0;
  while (str[j] == '-' || str[j] == '+')
    j++;
  while (str[j] >= '0' && str[j] <= '9')
    j++;
  if ((j = my_cpy_arg(ins, str, i, j)) == -1)
    return (NULL);
  return (str + j);
}
