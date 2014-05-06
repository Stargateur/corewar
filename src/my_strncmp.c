/*
** my_strncmp.c for my_strncmp in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct  7 14:50:07 2013 Antoine Plaskowski
** Last update Mon Dec 16 02:55:19 2013 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_strncmp(const char *s1, const char *s2, const int n)
{
  int		i;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
    i++;
  if (i == n)
    return (0);
  return (s1[i] - s2[i]);
}
