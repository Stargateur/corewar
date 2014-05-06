/*
** my_dump_memory.c for my_dump_memory in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr  9 20:52:15 2014 Antoine Plaskowski
** Last update Sun Apr 13 06:58:12 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"op.h"

int		my_dump_memory(const char *memory)
{
  int		i;

  if (memory == NULL)
    return (1);
  i = 0;
  while (i < MEM_SIZE)
    {
      my_putnbr_base((unsigned char)memory[i], "0123456789ABCDEF", 1);
      if ((unsigned char)memory[i++] < 0x10)
	my_putchar('0', 1);
      if (i % 32 == 0)
        my_putchar('\n', 1);
    }
  if (i % 32)
    my_putchar('\n', 1);
  return (0);
}

