/*
** my_read_file.c for my_read_file in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 10 15:12:39 2014 Antoine Plaskowski
** Last update Sat Apr 12 02:19:17 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_get_next_line.h"
#include	"my_open.h"
#include	"my_asm.h"
#include	"my_str.h"
#include	"op.h"

static int	my_cpy_comment(header_t *header, char *str)
{
  int		i;

  str += my_strlen(COMMENT_CMD_STRING);
  while (*str == ' ' || *str == '\t')
    str++;
  if (*str == '"')
    str++;
  i = 0;
  while (*str != '"' && *str != '\0' && i < COMMENT_LENGTH)
    header->comment[i++] = *str++;
  header->comment[i] = '\0';
  return (0);
}

static int	my_cpy_name(header_t *header, char *str)
{
  int		i;

  str += my_strlen(NAME_CMD_STRING);
  while (*str == ' ' || *str == '\t')
    str++;
  if (*str == '"')
    str++;
  i = 0;
  while (*str != '"' && *str != '\0' && i < PROG_NAME_LENGTH)
    header->prog_name[i++] = *str++;
  header->prog_name[i] = '\0';
  return (0);
}

static int	my_check_line(header_t *header, char **str)
{
  char		*tmp;
  int		i;

  if ((tmp = my_sup_comment(*str)) == NULL)
    return (1);
  free(*str);
  i = 0;
  while (tmp[i] == ' ' || tmp[i] == '\t')
    i++;
  if (my_strncmp(tmp + i, COMMENT_CMD_STRING,
		 my_strlen(COMMENT_CMD_STRING)) == 0)
    my_cpy_comment(header, tmp + i);
  else if (my_strncmp(tmp + i, NAME_CMD_STRING,
		      my_strlen(NAME_CMD_STRING)) == 0)
    my_cpy_name(header, tmp + i);
  if ((*str = my_epur_str(tmp)) == NULL)
    return (1);
  free(tmp);
  if (**str == '\0')
    return (1);
  else if (**str == '.')
    return (1);
  return (0);
}

t_ins		*my_read_file(header_t *header, char *file)
{
  t_ins		*ins;
  char		*str;
  int		fd;
  int		i;

  ins = NULL;
  i = 1;
  if (header == NULL || (fd = my_open_rdonly(file)) == -1)
    return (NULL);
  while ((str = my_get_next_line(fd)) != NULL)
    {
      if (my_check_line(header, &str) == 0)
	if ((ins = my_parse_line(ins, str, i)) == NULL)
	  return (my_put_error_line_null(i, str, "error on this line\n"));
      i++;
      free(str);
    }
  if (ins != NULL)
    while (ins->prev != NULL)
      ins = ins->prev;
  else
    return (my_put_error_null("no instruction\n"));
  return (ins);
}
