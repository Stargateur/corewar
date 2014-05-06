/*
** main.c for main in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 10 11:41:14 2014 Antoine Plaskowski
** Last update Mon Apr  7 11:37:26 2014 Antoine Plaskowski
*/

#include	<unistd.h>
#include	"my_asm.h"
#include	"my_str.h"
#include	"op.h"

static int	my_init_header(header_t *header)
{
  unsigned int	i;
  char		*tmp;

  tmp = (char *)header;
  i = 0;
  while (i < sizeof(header_t))
    tmp[i++] = 0;
  header->magic = COREWAR_EXEC_MAGIC;
  header->prog_size = 0;
  i = 0;
  while (i < PROG_NAME_LENGTH + 1)
    header->prog_name[i++] = 0;
  i = 0;
  while (i < COMMENT_LENGTH + 1)
    header->comment[i++] = 0;
  return (0);
}

static int	my_create_champion(char *champion, header_t *header)
{
  t_ins		*ins;
  int		fd;

  my_putstr(champion, 1);
  my_putchar('\n', 1);
  my_init_header(header);
  if ((ins = my_read_file(header, champion)) == NULL ||
      my_check_same_label(ins))
    return (1);
  my_set_size_ins(ins);
  header->prog_size = my_size_prog(ins);
  if ((fd = my_create_cor(champion)) == -1)
    return (1);
  if (my_write_header(header, fd))
    return (1);
  if (my_write_ins(ins, fd))
    return (1);
  my_free_ins(ins);
  return (0);
}

int		main(int argc, char **argv)
{
  header_t	header;
  int		i;

  i = 1;
  while (i < argc)
    {
      if (my_create_champion(argv[i++], &header))
	{
	  my_putstr("FAILURE\n", 2);
	  return (1);
	}
      my_putstr("SUCCESS\n", 1);
    }
  return (0);
}
