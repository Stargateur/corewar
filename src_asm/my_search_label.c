/*
** my_parse_line.c for my_parse_line in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 10 21:31:40 2014 Antoine Plaskowski
** Last update Wed Mar 12 13:33:29 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_asm.h"
#include	"my_str.h"

static int	my_nbr_label(char *str)
{
  int		i;

  i = 0;
  while (*str != '\0')
    {
      while (my_char_in_str(*str, LABEL_CHARS) != -1 && str[i] != '\0')
	str++;
      if (*str++ == LABEL_CHAR)
	i++;
      else
	return (i + 1);
      if (*str == ' ')
	str++;
    }
  return (i + 1);
}

static int	my_check_label(char *str)
{
  int		i;

  i = 0;
  while (my_char_in_str(str[i], LABEL_CHARS) != -1 && str[i] != '\0')
    i++;
  if (str[i++] == LABEL_CHAR)
    return (i);
  return (0);
}

char		*my_search_label(t_ins *ins, char *str)
{
  int		i;
  int		j;

  if (ins == NULL || str == NULL ||
      (ins->label = my_malloc(sizeof(char *) * my_nbr_label(str))) == NULL)
    return (NULL);
  j = 0;
  while (*str != '\0')
    {
      if ((i = my_check_label(str)) != 0)
	{
	  if ((ins->label[j++] = my_strndup(str, i - 1)) == NULL)
	    return (NULL);
	}
      else
	{
	  ins->label[j] = NULL;
	  return (str);
	}
      if (str[i] == ' ')
	i++;
      str += i;
    }
  ins->label[j] = NULL;
  return (str);
}
