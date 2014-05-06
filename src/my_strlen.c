/*
** my_strlen.c for my_strlen in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 10:50:55 2013 Antoine Plaskowski
** Last update Mon Apr  7 11:34:22 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_strlen(const char *str)
{
  const char	*tmp;

  if (str == NULL)
    return (0);
  tmp = str;
  while (*str != '\0')
    str++;
  return (str - tmp);
}
