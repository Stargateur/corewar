/*
** my_sup_comment.c for my_sup_comment in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Mar 11 13:12:07 2014 Antoine Plaskowski
** Last update Sun Mar 23 17:22:43 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"op.h"

char		*my_sup_comment(char *str)
{
  char		*new;
  int		i;

  i = 0;
  while (str[i] != COMMENT_CHAR && str[i] != '\0')
    i++;
  if ((new = my_malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != COMMENT_CHAR && str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
