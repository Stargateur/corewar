/*
** my_str.h for my_str in /home/plasko_a/rendu/PSU_2013_minishell1/header
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Dec 14 23:00:22 2013 Antoine Plaskowski
** Last update Sun Apr 13 20:04:29 2014 Antoine Plaskowski
*/

#ifndef		MY_STR_H_
# define	MY_STR_H_

typedef struct	s_str t_str;
struct		s_str
{
  t_str		*prev;
  char		*str;
  t_str		*next;
};

int		my_putchar(const char c, const int fd);
int		my_putstr(const char *str, const int fd);
int		my_strlen(const char *str);
int		my_putnbr(int nb, const int fd);
int		my_putnbr_base(int nb, const char *base, const int fd);
int		my_strcpy(char *dest, const char *src);
int		my_strncpy(char *dest, const char *src, int n);
int		my_getnbr(const char *str);
char		*my_strdup(const char *str);
char		*my_strndup(const char *str, int n);
char		*my_strcat(const char *str1, const char *str2);
int		my_strcmp(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, const int n);
int		my_char_in_str(const char c, const char *str);
char		*my_epur_str(char *str);
char		*my_sup_space(char *str);

void		*my_malloc(int size_octect);
void		*my_calloc(int size_octect);

/*
**		my_str.c
*/

t_str		*my_put_str(t_str *old, char *str);
void		my_free_str(t_str *str);
int		my_aff_str(t_str *str);

/*
**		my_rev_oct.c
*/

int		my_rev_oct(void *oct, int octect);
int		my_put_oct(void *oct,  int val);
int		my_put_oct_modulo(void *oct, int pc, int nb, int octect);
int		my_putnbr_oct(int oct,  int octect, const int fd);
int		my_read_oct(void *oct, int octect);
int		my_read_oct_modulo(void *oct, int pc, int octect);
int		my_write_oct(void *data, int octect, int fd);

/*
**		my_put_error.c
*/

int		my_put_error(char *str);
void		*my_put_error_null(char *str);
int		my_put_error_line(int i, char *str, char *error);
void		*my_put_error_line_null(int i, char *str, char *error);

#endif		/* MY_STR_ */
