/*
** main.c for main in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 05:47:30 2014 Antoine Plaskowski
** Last update Sun Apr 13 09:09:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"
#include	"my_str.h"

static int	my_set_vm(t_vm *vm)
{
  vm->x_die = CYCLE_TO_DIE;
  return (0);
}

static int	my_free_vm(t_vm *vm)
{
  my_free_champ(vm->champ);
  my_free_proc(vm->proc);
  free(vm);
  return (0);
}

int		main(int argc, char **argv)
{
  t_vm		*vm;

  (void)argc;
  if ((vm = my_calloc(sizeof(t_vm))) == NULL)
    return (1);
  my_set_vm(vm);
  if (my_prepare_vm(vm, argv))
    return (1);
  my_core(vm);
  my_free_vm(vm);
  return (0);
}
