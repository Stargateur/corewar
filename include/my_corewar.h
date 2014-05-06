/*
** my_corewar.h for my_corewar in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Apr 12 23:18:49 2014 Antoine Plaskowski
** Last update Sun Apr 13 22:51:45 2014 Antoine Plaskowski
*/

#ifndef		MY_COREWAR_H_
# define	MY_COREWAR_H_

# include	"op.h"

typedef	struct	s_champ	t_champ;
typedef	struct	s_proc	t_proc;
typedef	struct	s_arg	t_arg;
typedef	struct	s_vm	t_vm;

struct		s_arg
{
  int		type;
  int		value;
  int		arg;
};

struct		s_proc
{
  t_proc	*prev;
  int		reg[REG_NUMBER];
  int		x_wait;
  int		opcode;
  int		id;
  int		pc;
  int		carry;
  t_proc	*next;
};

struct		s_champ
{
  t_champ	*prev;
  char		*path;
  char		*prog;
  int		id;
  int		pc;
  int		alive;
  header_t	head;
  t_champ	*next;
};

struct		s_vm
{
  t_champ	*champ;
  t_proc	*proc;
  int		dump;
  int		x_dump;
  int		x_die;
  int		nbr_live;
  int		id_last_live;
  char		mem[MEM_SIZE];
};

/*
**
**		my_core
**
*/

int		my_dump_memory(const char *memory);

int		my_core(t_vm *vm);

int		my_do_one_cycle(t_vm *vm);

int		my_give_type_codage(int octect, int i);

int		my_parse_arg(t_arg *arg, char *mem, int opcode, int pc);

int		my_parse_arg_special(t_arg *arg, char *mem, int opcode, int pc);

int		my_load_in_mem(t_arg *arg, t_proc *proc, char *mem, int opcode);

int		my_value_if_reg(t_arg *arg);

/*
**
**		my_core/my_ins
**
*/

int		my_live(t_vm *vm, t_proc *proc, int opcode);
int		my_ld(t_vm *vm, t_proc *proc, int opcode);
int		my_st(t_vm *vm, t_proc *proc, int opcode);
int		my_add(t_vm *vm, t_proc *proc, int opcode);
int		my_sub(t_vm *vm, t_proc *proc, int opcode);
int		my_and(t_vm *vm, t_proc *proc, int opcode);
int		my_or(t_vm *vm, t_proc *proc, int opcode);
int		my_xor(t_vm *vm, t_proc *proc, int opcode);
int		my_zjmp(t_vm *vm, t_proc *proc, int opcode);
int		my_ldi(t_vm *vm, t_proc *proc, int opcode);
int		my_sti(t_vm *vm, t_proc *proc, int opcode);
int		my_fork(t_vm *vm, t_proc *proc, int opcode);
int		my_lld(t_vm *vm, t_proc *proc, int opcode);
int		my_lldi(t_vm *vm, t_proc *proc, int opcode);
int		my_lfork(t_vm *vm, t_proc *proc, int opcode);
int		my_aff(t_vm *vm, t_proc *proc, int opcode);

/*
**
**		my_prepare_vm
**
*/

t_champ		*my_create_champ(char **argv);

t_proc		*my_create_proc(t_champ *champ);

int		my_define_id_champ(t_champ *champ, int id);

int		my_dump_option(char **argv, int *dump, int *x_dump);

int		my_prepare_vm(t_vm *vm, char **argv);

int		my_read_header(header_t *header, int fd);

int		my_size_total_champ(t_champ *champ);

int		my_spread_champ(t_champ *champ, char *mem);

/*
**
**		my_champ
**
*/

void		my_free_champ(t_champ *champ);

t_champ		*my_new_champ(void);

t_champ		*my_put_champ(t_champ *old, t_champ *champ);

/*
**		my_tool_champ.c
*/

t_champ		*my_first_elem_champ(t_champ *champ);
t_champ		*my_last_elem_champ(t_champ *champ);
int		my_len_champ(t_champ *champ);

/*
**		END
*/

/*
**
**		my_proc
**
*/

void		my_free_proc(t_proc *proc);

t_proc		*my_new_proc(void);

t_proc		*my_put_proc(t_proc *old, t_proc *proc);

t_proc		*my_sup_proc(t_proc *old);

t_proc		*my_cpy_proc(t_proc *src);

/*
**		my_tool_proc.c
*/

t_proc		*my_first_elem_proc(t_proc *proc);
t_proc		*my_last_elem_proc(t_proc *proc);
int		my_len_proc(t_proc *proc);

/*
**		END
*/

#endif		/* !MY_COREWAR_H_ */
