/*
** my_asm.h for my_asm in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 10 17:23:00 2014 Antoine Plaskowski
** Last update Wed Apr  9 21:20:33 2014 Antoine Plaskowski
*/

#ifndef		MY_ASM_H_
# define	MY_ASM_H_

# include	"op.h"

typedef struct	s_arg t_arg;
typedef struct	s_ins t_ins;

struct		s_arg
{
  int		type;
  char		*arg;
};

struct		s_ins
{
  t_ins		*prev;
  char		**label;
  int		ins;
  t_arg		arg[MAX_ARGS_NUMBER];
  int		octect;
  int		line_number;
  unsigned char	octect_codage;
  t_ins		*next;
};

/*
**		my_read_file.c
*/

t_ins		*my_read_file(header_t *header, char *file);

/*
**		my_ins.c
*/

t_ins		*my_new_ins(void);
t_ins		*my_put_ins(t_ins *old, t_ins *ins);
void		my_free_ins(t_ins *ins);
int		my_check_ins(t_ins *ins, char *str);

/*
**		my_seach_label.c
*/

char		*my_search_label(t_ins *ins, char *str);

/*
**		my_parse_arg.c
*/

int		my_cpy_arg(t_ins *ins, char *str, int i, int j);
int		my_parse_arg(t_ins *ins, char *str);

/*
**		my_parse_line.c
*/

t_ins		*my_parse_line(t_ins *ins, char *str, int i);

/*
**		my_parse_direct.c
*/

char		*my_parse_direct(t_ins *ins, char *str, int i);

/*
**		my_parse_direct.c
*/

char		*my_parse_indirect(t_ins *ins, char *str, int i);

/*
**		my_parse_direct.c
*/

char		*my_parse_registre(t_ins *ins, char *str, int i);

/*
**		my_parse_direct.c
*/

char		*my_parse_label(t_ins *ins, char *str, int i);

/*
**		my_sup_comment.c
*/

char		*my_sup_comment(char *str);

/*
**		my_set_size_ins.c
*/

int		my_set_size_ins(t_ins *ins);
int		my_size_prog(t_ins *ins);

/*
**		my_create_cor.c
*/

int		my_create_cor(char *name);

/*
**		my_write_header.c
*/

int		my_write_header(header_t *header, int fd);

/*
**		my_write_registre.c
*/

int		my_write_registre(t_ins *ins, int i, int fd);

/*
**		my_write_indirect.c
*/

int		my_write_indirect(t_ins *ins, int i, int fd);

/*
**		my_write_direct.c
*/

int		my_write_direct(t_ins *ins, int i, int fd);

/*
**		my_write_label.c
*/

int		my_write_label(t_ins *ins, int i, int fd, int special);

/*
**		my_write_ins.c
*/

int		my_write_ins(t_ins *ins, int fd);

/*
**		my_write_normal.c
*/

int		my_write_normal(t_ins *ins, int fd);

/*
**		my_write_special.c
*/

int		my_write_special(t_ins *ins, int fd);

/*
**		my_write_no_codage.c
*/

int		my_write_no_codage(t_ins *ins, int fd);

/*
**		my_write_special_no_codage.c
*/

int		my_write_special_no_codage(t_ins *ins, int fd);

/*
**		my_set_octect_codage.c
*/

int		my_set_octect_codage(t_ins *ins);

/*
**		my_size_normal.c
*/

int		my_size_normal(t_ins *ins);

/*
**		my_size_special.c
*/

int		my_size_special(t_ins *ins);

/*
**		my_size_3.c
*/

int		my_size_special_no_codage(t_ins *ins);

/*
**		my_size_5.c
*/

int		my_size_no_codage(t_ins *ins);

/*
**		my_check_same_label.c
*/

int		my_check_same_label(t_ins *ins);

#endif		/* !MY_ASM_H_ */
