/*
** my_give_type_codage.c for my_give_type_codage in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_core/my_ins
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 09:15:25 2014 Antoine Plaskowski
** Last update Sun Apr 13 09:15:26 2014 Antoine Plaskowski
*/

#include	"op.h"

int		my_give_type_codage(char octect, int i)
{
  if ((octect & 1 << (7 - i * 2)) == 0 &&
      (octect & 1 << (7 - i * 2 - 1)))
    return (T_REG);
  else if ((octect & 1 << (7 - i * 2)) &&
	   (octect & 1 << (7 - i * 2 - 1)) == 0)
    return (T_DIR);
  else if ((octect & 1 << (7 - i * 2)) &&
	   (octect & 1 << (7 - i * 2 - 1)))
    return (T_IND);
  return (0);
}
