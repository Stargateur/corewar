/*
** my_create_champ.c for my_create_champ in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_prepare_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 05:10:46 2014 Antoine Plaskowski
** Last update Sun Apr 13 13:11:40 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_corewar.h"
#include	"my_open.h"
#include	"my_str.h"

static int	my_gere_opt(char **argv, int *id, int *pc)
{
  if (*(argv + 1) == NULL)
    return (my_put_error("need something after a option\n"));
  if (my_strcmp(*argv, "-n") == 0)
    *id = my_getnbr(*(argv + 1));
  else if (my_strcmp(*argv, "-a") == 0)
    {
      if ((*pc = my_getnbr(*(argv + 1)) % MEM_SIZE) < 0)
	return (my_put_error("You can't put a PC negative\n"));
    }
  return (0);
}

static char	*my_read_prog(int prog_size, int fd)
{
  char		*prog;
  char		tmp;

  if ((prog = my_calloc(sizeof(char) * prog_size)) == NULL)
    return (NULL);
  if (read(fd, prog, prog_size) != prog_size)
    return (my_put_error_null("Champion incorect\n"));
  if (read(fd, &tmp, 1) != 0)
    return (my_put_error_null("Champion incorect\n"));
  return (prog);
}

static int	my_read_champ(t_champ *champ)
{
  int		fd;

  if ((fd = my_open_rdonly(champ->path)) == -1)
    return (1);
  if (my_read_header(&champ->head, fd))
    return (1);
  if ((champ->prog = my_read_prog(champ->head.prog_size, fd)) == NULL)
    return (1);
  close(fd);
  return (0);
}

static t_champ	*my_init_champ(t_champ *old, char *path, int pc, int id)
{
  t_champ	*champ;

  if ((champ = my_new_champ()) == NULL)
    return (NULL);
  if ((champ->path = my_strdup(path)) == NULL)
    return (NULL);
  if (my_read_champ(champ))
    return (NULL);
  champ->pc = pc;
  if ((champ->id = my_define_id_champ(old, id)) == -1)
    return (NULL);
  return (my_put_champ(old, champ));
}

t_champ		*my_create_champ(char **argv)
{
  t_champ	*champ;
  int		id;
  int		pc;

  if (argv == NULL)
    return (NULL);
  champ = NULL;
  id = -1;
  pc = -1;
  while (*++argv != NULL)
    if (**argv == '-')
      {
	if (my_gere_opt(argv++, &id, &pc))
	  return (NULL);
      }
    else
      {
	if ((champ = my_init_champ(champ, *argv, pc, id)) == NULL)
	  return (NULL);
	id = -1;
	pc = -1;
      }
  return (my_first_elem_champ(champ));
}
