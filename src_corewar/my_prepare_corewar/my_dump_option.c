/*
** my_dump_option.c for my_dump_option in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Apr 12 23:36:23 2014 Antoine Plaskowski
** Last update Sun Apr 13 06:36:28 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

int		my_dump_option(char **argv, int *dump, int *x_dump)
{
  int		i;

  if (argv == NULL || dump == NULL || x_dump == NULL)
    return (1);
  i = 0;
  *dump = 0;
  *x_dump = 0;
  while (argv[i] != NULL)
    if (my_strncmp(argv[i++], "-dump", my_strlen("-dump")) == 0)
      {
	if (argv[i] == NULL)
	  return (my_put_error("need something after a option\n"));
	*x_dump = my_getnbr(argv[i]);
	*dump = 1;
      }
  return (0);
}
