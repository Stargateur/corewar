/*
** my_str.c for my_str in /home/plasko_a/rendu/PSU_2013_minitalk
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Feb 25 19:06:12 2014 Antoine Plaskowski
** Last update Mon Mar 10 17:18:25 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_str.h"

t_str		*my_put_str(t_str *old, char *str)
{
  t_str		*new;

  if ((new = my_malloc(sizeof(t_str))) == NULL)
    return (NULL);
  new->str = str;
  new->next = NULL;
  if (old == NULL)
    new->prev = NULL;
  else
    {
      while (old->next != NULL)
	old = old->next;
      new->prev = old;
      old->next = new;
    }
  return (new);
}

void		my_free_str(t_str *str)
{
  t_str		*tmp;

  if (str != NULL)
    {
      while (str->prev != NULL)
	str = str->prev;
      while (str != NULL)
	{
	  free(str->str);
	  tmp = str;
	  str = str->next;
	  free(tmp);
	}
    }
}

int		my_aff_str(t_str *str)
{
  if (str == NULL)
    return (1);
  while (str->prev != NULL)
    str = str->prev;
  while (str != NULL)
    {
      my_putstr(str->str, 1);
      my_putchar('\n', 1);
      str = str->next;
    }
  return (0);
}
