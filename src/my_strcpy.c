/*
** my_strcpy.c for my_strcpy in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct  7 09:22:05 2013 Antoine Plaskowski
** Last update Sun Apr  6 20:02:04 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_strcpy(char *dest, const char *src)
{
  int		i;

  if (dest == NULL || src == NULL)
    return (1);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (0);
}
