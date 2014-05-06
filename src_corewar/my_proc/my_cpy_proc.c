/*
** my_cpy_proc.c for my_cpy_proc in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 14:59:09 2014 Antoine Plaskowski
** Last update Sun Apr 13 15:18:48 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_corewar.h"

t_proc		*my_cpy_proc(t_proc *src)
{
  t_proc	*dest;
  char		*tmp_src;
  char		*tmp_dest;
  unsigned int	i;

  if (src == NULL)
    return (NULL);
  if ((dest = my_new_proc()) == NULL)
    return (NULL);
  tmp_src = (char *)src;
  tmp_dest = (char *)dest;
  i = 0;
  while (i < sizeof(t_proc))
    {
      tmp_dest[i] = tmp_src[i];
      i++;
    }
  dest->prev = NULL;
  dest->next = NULL;
  return (dest);
}
