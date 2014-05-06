/*
** my_check_octect_codage.c for my_check_octect_codage in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 25 14:14:53 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:28:43 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"op.h"

static int	my_verif(int ins, int *tab, int i)
{
  if (tab[i] != 0)
    {
      if (i > op_tab[ins].nbr_args)
	return (1);
      else if (op_tab[ins].type[i] == T_REG && tab[i] != T_REG)
	return (1);
      else if (op_tab[ins].type[i] == T_IND && tab[i] != T_IND && tab[i] != T_DIR)
	return (1);
      else if (op_tab[ins].type[i] == T_DIR && tab[i] != T_IND)
	return (1);
    }
  return (0);
}

int		my_check_octect_codage(int ins, char octect, int *tab)
{
  int		i;

  i = 0;
  while (i < MAX_ARGS_NUMBER)
    {
      if ((octect & 1 << (7 - i * 2)) == 0 &&
	  (octect & 1 << (7 - i * 2 - 1)))
	tab[i] = T_REG;
      else if ((octect & 1 << (7 - i * 2)) &&
	       (octect & 1 << (7 - i * 2 - 1)) == 0)
	tab[i] = T_DIR;
      else if ((octect & 1 << (7 - i * 2)) &&
	       (octect & 1 << (7 - i * 2 - 1)))
	tab[i] = T_IND;
      else
	tab[i] = 0;
      if (my_verif(ins, tab, i++))
	return (my_put_error("byte coding is not valid\n"));
    }
  return (0);
}
