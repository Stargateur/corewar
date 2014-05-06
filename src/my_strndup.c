/*
** my_strndup.c for my_strndup in /home/plasko_a/rendu/PSU_2013_minishell2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Feb 19 22:47:44 2014 Antoine Plaskowski
** Last update Wed Apr  9 12:40:01 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

char		*my_strndup(const char *str, int n)
{
  char		*cpy;
  int		len;

  if (str == NULL)
    return (NULL);
  if ((len = my_strlen(str)) < n)
    n = len;
  if ((cpy = my_malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  if (my_strncpy(cpy, str, n))
    {
      free(cpy);
      return (NULL);
    }
  return (cpy);
}
