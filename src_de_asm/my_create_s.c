/*
** my_create_s.c for my_create_s in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Mar 24 19:13:43 2014 Antoine Plaskowski
** Last update Sun Apr  6 11:04:50 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"my_open.h"

static int	my_len_name(char *name)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (name[i] != '\0')
    {
      if (name[i] == '.')
	j = i;
      i++;
    }
  return (j);
}

static char	*my_new_name(char *name)
{
  char		*str;
  int		i;

  if ((i = my_len_name(name)) == 0)
    i = my_strlen(name);
  if ((str = my_malloc(sizeof(char) * (i + my_strlen(".s") + 1))) == NULL)
    return (NULL);
  my_strncpy(str, name, i);
  my_strcpy(str + i, ".s");
  return (str);
}

int		my_create_s(char *name)
{
  char		*str;
  int		fd;

  if ((str = my_new_name(name)) == NULL)
    return (1);
  fd = my_open_wrtr(str);
  free(str);
  return (fd);
}
