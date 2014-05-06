/*
** my_rev_oct.c for my_rev_oct in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 10 21:01:03 2014 Antoine Plaskowski
** Last update Fri Mar 21 13:38:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_rev_oct(void *oct, int octect)
{
  char		*tmp;
  int		i;
  char		c;

  if (oct == NULL)
    return (1);
  tmp = (char *)oct;
  i = 0;
  while (i < octect / 2)
    {
      c = tmp[i];
      tmp[i] = tmp[octect - 1 - i];
      tmp[octect - 1 - i++] = c;
    }
  return (0);
}
