/*
** op.h for op in
** 
** Made by Nicolas Sadirac
** Login   <>
** 
** Started on  Mon Jan 01 00:00:00 1993 Nicolas Sadirac
** Last update Wed Apr 16 19:13:25 2014 Antoine Plaskowski
*/

#ifndef		OP_H_
# define	OP_H_

# define	MEM_SIZE		(6*1024)
# define	IDX_MOD			512
# define	MAX_ARGS_NUMBER		4
# define	REG_NUMBER		16

# define	COMMENT_CHAR		'#'
# define	LABEL_CHAR		':'
# define	DIRECT_CHAR		'%'
# define	SEPARATOR_CHAR		','

# define	LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define	NAME_CMD_STRING		".name"
# define	COMMENT_CMD_STRING	".comment"

# define	T_REG			1
# define	T_DIR			2
# define	T_IND			4
# define	T_LAB			8

# define	IND_SIZE		2
# define	REG_SIZE		4
# define	DIR_SIZE		REG_SIZE

# define	PROG_NAME_LENGTH	128
# define	COMMENT_LENGTH		2048

# define	COREWAR_EXEC_MAGIC	0xea83f3

# define	CYCLE_TO_DIE		1536
# define	CYCLE_DELTA		4
# define	NBR_LIVE		2048

typedef struct	op_s op_t;
struct		op_s
{
   char		*mnemonique;
   char		nbr_args;
   char		type[MAX_ARGS_NUMBER];
   char		code;
   int		nbr_cycles;
   char		*comment;
};

extern  op_t    op_tab[];

typedef struct	header_s header_t;
struct		header_s
{
   int		magic;
   char		prog_name[PROG_NAME_LENGTH + 1];
   int		prog_size;
   char		comment[COMMENT_LENGTH + 1];
};

#endif		/* !OP_H_*/
