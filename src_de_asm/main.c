/*
** main.c for main in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Mar 24 15:15:21 2014 Antoine Plaskowski
** Last update Wed Apr 16 19:14:24 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_open.h"
#include	"op.h"
#include	"my_str.h"
#include	"my_de_asm.h"

static int	my_read_header(header_t *header, int fd)
{
  if (read(fd, header, sizeof(header_t)) != sizeof(header_t))
    return (my_put_error("wrong header\n"));
  my_rev_oct(&(header->magic), sizeof(header->magic));
  my_rev_oct(&(header->prog_size), sizeof(header->prog_size));
  header->prog_name[PROG_NAME_LENGTH] = '\0';
  header->comment[COMMENT_LENGTH] = '\0';
  if (header->magic != COREWAR_EXEC_MAGIC)
    return (my_put_error("wrong magic number"));
  return (0);
}

static int	my_dump_champ(header_t *header, char *champ)
{
  int		i;

  my_putstr(header->prog_name, 1);
  my_putchar('\n', 1);
  i = 0;
  while (i < header->prog_size)
    {
      my_putnbr_base((unsigned char)champ[i], "0123456789ABCDEF", 1);
      if ((unsigned char)champ[i] < 0x10)
	my_putchar('0', 1);
      i++;
      if (i % 32 == 0)
	my_putchar('\n', 1);
    }
  if (i % 32)
    my_putchar('\n', 1);
  return (0);
}

static char	*my_init(header_t *header, char *name)
{
  char		*champ;
  int		fd;

  if ((fd = my_open_rdonly(name)) == -1)
    return (NULL);
  if (my_read_header(header, fd))
    return (NULL);
  if ((champ = my_read_champion(header, fd)) == NULL)
    return (my_put_error_null("Champion invalide\n"));
  close(fd);
  return (champ);
}

static int	my_create_champion(header_t *header, char *champion)
{
  char		*champ;
  int		fd;

  my_putstr(champion, 1);
  my_putchar('\n', 1);
  if ((champ = my_init(header, champion)) == NULL)
    return (1);
  if ((fd = my_create_s(champion)) == -1)
    return (1);
  my_dump_champ(header, champ);
  if (my_write_header(header, fd))
    return (1);
  if (my_write_ins(header, champ, fd))
    return (1);
  close(fd);
  free(champ);
  return (0);
}

int		main(int argc, char **argv)
{
  header_t	header;
  int		i;

  i = 1;
  while (i < argc)
    {
      if (my_create_champion(&header, argv[i++]))
	{
	  my_putstr("FAILURE\n", 2);
	  return (1);
	}
      my_putstr("SUCCESS\n", 1);
    }
  return (0);
}
