/*
** my_put_oct.c for my_put_oct in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 18 20:37:55 2014 Antoine Plaskowski
** Last update Thu Mar 20 19:10:28 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_put_oct(void *oct, int val)
{
  char		*tmp;
  char		*p;
  int		i;

  if (oct == NULL)
    return (1);
  tmp = (char *)oct;
  p = (char *)&val;
  i = 0;
  while (i < 4)
    {
      tmp[i] = p[4 - i - 1];
      i++;
    }
  return (0);
}
