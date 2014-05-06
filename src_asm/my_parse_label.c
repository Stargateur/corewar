/*
** my_parse_arg.c for my_parse_arg in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 11 16:10:05 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:17:37 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"

char		*my_parse_label(t_ins *ins, char *str, int i)
{
  int		j;

  if ((op_tab[ins->ins].type[i] & T_IND) == 0)
    return (my_put_error_null("wrong type of argument\n"));
  str++;
  j = 0;
  ins->arg[i].type = T_LAB + T_IND;
  if (my_char_in_str(str[j], LABEL_CHARS) != -1)
    while (my_char_in_str(str[j], LABEL_CHARS) != -1)
      j++;
  else
    return (my_put_error_null("wrong type of argument\n"));
  if ((j = my_cpy_arg(ins, str, i, j)) == -1)
    return (NULL);
  return (str + j);
}
