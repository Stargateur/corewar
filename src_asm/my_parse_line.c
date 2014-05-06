/*
** my_parse_line.c for my_parse_line in /home/plasko_a/rendu/corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr  6 08:38:41 2014 Antoine Plaskowski
** Last update Sun Apr  6 11:07:57 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"
#include	"op.h"

static int	my_check_nmemonique(char *str, int j)
{
  char		*tmp;

  tmp = op_tab[j].mnemonique;
  if (my_strncmp(str, tmp, my_strlen(tmp)) == 0 &&
      (*(str + my_strlen(tmp)) == ' ' ||
       *(str + my_strlen(tmp)) == '\0'))
    return (1);
  return (0);
}

t_ins		*my_parse_line(t_ins *ins, char *str, int i)
{
  t_ins		*new;
  int		j;

  if ((new = my_new_ins()) == NULL)
    return (NULL);
  new->line_number = i;
  if ((str = my_search_label(new, str)) == NULL)
    return (NULL);
  j = 0;
  while (op_tab[j].mnemonique != NULL)
    {
      if (my_check_nmemonique(str, j))
        {
          new->ins = j;
          if (my_parse_arg(new, str + my_strlen(op_tab[j].mnemonique) + 1))
            return (NULL);
          return (my_put_ins(ins, new));
        }
      j++;
    }
  if (my_check_ins(new, str))
    return (NULL);
  return (my_put_ins(ins, new));
}
