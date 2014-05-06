/*
** my_prepare_vm.c for my_prepare_vm in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_prepare_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 05:38:59 2014 Antoine Plaskowski
** Last update Sun Apr 13 07:36:15 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

int		my_prepare_vm(t_vm *vm, char **argv)
{
  if (vm == NULL || argv == NULL)
    return (1);
  my_dump_option(argv, &vm->dump, &vm->x_dump);
  if ((vm->champ = my_create_champ(argv)) == NULL)
    return (1);
  if (my_size_total_champ(vm->champ) > MEM_SIZE)
    return (my_put_error("Can't place all champions there are too big\n"));
  if (my_spread_champ(vm->champ, vm->mem))
    return (1);
  if ((vm->proc = my_create_proc(vm->champ)) == NULL)
    return (1);
  return (0);
}
