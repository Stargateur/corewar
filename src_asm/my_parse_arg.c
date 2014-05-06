/*
** my_parse_arg.c for my_parse_arg in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 11 16:10:05 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:15:58 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"

int		my_cpy_arg(t_ins *ins, char *str, int i, int j)
{
  if ((ins->arg[i].arg = my_strndup(str, j)) == NULL)
    return (-1);
  if (str[j] == ' ')
    j++;
  if (i + 1 < op_tab[ins->ins].nbr_args)
    {
      if (str[j] != SEPARATOR_CHAR)
	return (-1);
    }
  else
    if (str[j] != '\0')
      return (-1);
  if (str[j] == SEPARATOR_CHAR)
    j++;
  if (str[j] == ' ')
    j++;
  return (j);
}

static char	*(*g_fct_par_arg[])(t_ins *, char *, int) =
{
  &my_parse_direct,
  &my_parse_registre,
  &my_parse_indirect,
  &my_parse_label
};

int		my_parse_arg(t_ins *ins, char *str)
{
  int		i;
  int		j;

  if (ins == NULL || str == NULL)
    return (my_put_error("internal error\n"));
  i = 0;
  while (*str != '\0' && i < op_tab[ins->ins].nbr_args)
    {
      j = -1;
      if (*str == DIRECT_CHAR)
	j = 0;
      else if (*str == 'r')
	j = 1;
      else if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+')
	j = 2;
      else if (*str == LABEL_CHAR)
	j = 3;
      if (j == -1 || (str = g_fct_par_arg[j](ins, str, i++)) == NULL)
	return (1);
    }
  if (*str != '\0' || i != op_tab[ins->ins].nbr_args)
    return (my_put_error("incorrect number of arguments\n"));
  return (0);
}
