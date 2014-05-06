/*
** my_de_asm.h for my_de_asm in /home/plasko_a/rendu/CPE_2014_corewar
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar 24 20:09:49 2014 Antoine Plaskowski
** Last update Thu Apr  3 15:58:49 2014 Antoine Plaskowski
*/

#ifndef		MY_DE_ASM_H_
# define	MY_DE_ASM_H_

# include	"op.h"

char		*my_read_champion(header_t *header, int fd);
int		my_create_s(char *name);
int		my_write_header(header_t *header, int fd);
int		my_write_ins(header_t *header, char *champ, int fd);
int		my_write_registre(header_t *header, char *champ, int i, int fd);
int		my_write_indirect(header_t *header, char *champ, int i, int fd);
int		my_write_direct(header_t *header, char *champ, int i, int fd);
int		my_check_octect_codage(int ins, char octect, int *tab);
int		my_write_normal(header_t *header, char *champ, int i, int fd);
int		my_write_special(header_t *header, char *champ, int i, int fd);
int		my_write_3(header_t *header, char *champ, int i, int fd);
int		my_write_5(header_t *header, char *champ, int i, int fd);

#endif		/* !MY_DE_ASM_H_ */
