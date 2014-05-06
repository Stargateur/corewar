/*
** my_parse_arg.c for my_parse_arg in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 11 16:10:05 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:16:59 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"

static  char	*my_parse_label_direct(t_ins *ins, char *str, int i)
{
  int		j;

  str++;
  j = 0;
  ins->arg[i].type = T_LAB + T_DIR;
  if (my_char_in_str(str[j], LABEL_CHARS) != -1)
    while (my_char_in_str(str[j], LABEL_CHARS) != -1)
      j++;
  else
    return (my_put_error_null("wrong type of argument\n"));
  if ((j = my_cpy_arg(ins, str, i, j)) == -1)
    return (NULL);
  return (str + j);
}

char		*my_parse_direct(t_ins *ins, char *str, int i)
{
  int		j;

  if ((op_tab[ins->ins].type[i] & T_DIR) == 0)
    return (my_put_error_null("wrong type of argument\n"));
  str++;
  j = 0;
  ins->arg[i].type = T_DIR;
  if ((str[j] >= '0' && str[j] <= '9') || str[j] == '-' || str[j] == '+')
    {
      while (str[j] == '-' || str[j] == '+')
	j++;
      while (str[j] >= '0' && str[j] <= '9')
	j++;
    }
  else if (*str == LABEL_CHAR)
    return (my_parse_label_direct(ins, str, i));
  else
    return (my_put_error_null("wrong type of argument\n"));
  if ((j = my_cpy_arg(ins, str, i, j)) == -1)
    return (NULL);
  return (str + j);
}
