/*
** my_value_if_reg.c for my_value_if_reg in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 18:48:54 2014 Antoine Plaskowski
** Last update Sun Apr 13 18:49:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<my_corewar.h>

int		my_value_if_reg(t_arg *arg)
{
  if (arg == NULL)
    return (0);
  if (arg->type == T_REG)
    return (arg->value);
  return (arg->arg);
}

