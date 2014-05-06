/*
** my_epur_str.c for my_epur_str in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 10 18:23:06 2014 Antoine Plaskowski
** Last update Mon Mar 10 21:19:34 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

static int	my_len_epur_str(char *str)
{
  int		i;

  i = 0;
  while (*str != '\0')
    {
      while (*str != ' ' && *str != '\t' && *str != '\0')
	{
	  i++;
	  str++;
	}
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != '\0')
	i++;
    }
  return (i + 1);
}

char		*my_epur_str(char *str)
{
  char		*epur;
  int		i;

  if (str == NULL)
    return (NULL);
  if ((epur = my_malloc(sizeof(char) * my_len_epur_str(str))) == NULL)
    return (NULL);
  while (*str == ' ' || *str == '\t')
    str++;
  i = 0;
  while (*str != '\0')
    {
      while (*str != ' ' && *str != '\t' && *str != '\0')
	epur[i++] = *str++;
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != '\0')
	epur[i++] = ' ';
    }
  epur[i] = '\0';
  return (epur);
}
