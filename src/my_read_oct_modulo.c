/*
** my_read_oct_modulo.c for my_read_oct_modulo in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Apr 10 19:33:28 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:29:28 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"op.h"

static int	my_octect_is_pos(int oct, int octect)
{
  int		i;
  int		j;

  i = 1;
  j = 1;
  while (j < octect * 8 - 1)
    {
      i *= 2;
      j++;
    }
  if (!(i & oct))
    return (1);
  return (0);
}

static int	my_nbr_pos(int oct, int octect)
{
  int		result;
  int		i;
  int		j;

  result = 0;
  i = 1;
  j = 1;
  while (j++ < octect * 8 - 1)
    {
      if (i & oct)
	result += i;
      i *= 2;
    }
  return (result);
}

static int	my_nbr_neg(int oct, int octect)
{
  int		result;
  int		i;
  int		j;

  result = -1;
  i = 1;
  j = 1;
  while (j++ < octect * 8 - 1)
    {
      if (!(i & oct))
	result -= i;
      i *= 2;
    }
  return (result);
}

int		my_read_oct_modulo(void *oct, int pc, int octect)
{
  char		*tmp;
  char		*p;
  int		i;
  int		result;

  if (octect < 1 || octect > 4)
    return (0);
  if (oct == NULL)
    return (1);
  tmp = (char *)oct;
  p = (char *)&result;
  result = 0;
  i = 0;
  while (i < octect)
    {
      p[i] = tmp[((pc + octect - i - 1) % MEM_SIZE + MEM_SIZE) % MEM_SIZE];
      i++;
    }
  if (my_octect_is_pos(result, octect))
    return (my_nbr_pos(result, octect));
  return (my_nbr_neg(result, octect));
}
