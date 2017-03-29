/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:38:35 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 18:04:12 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>

# define BUFF_SIZE	1

# define ERROR 	1
# define SUCCESS 0

/*
**	Colors
*/
# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"
# define C_UNDERLINE    "\033[4m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Print Functions
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putnendl(char const *str, int n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *str, int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_clair(char const *s);
void				ft_putendl_clair_fd(char const *s, int fd);
void				ft_put_tab(char **mytab);
void				ft_put_tab_fd(char **mytab, int fd);

/*
** Str Functions
*/
size_t				ft_strlen(const char *s);
size_t				ft_nbrlen(int nbr);
size_t				ft_tablen(char **mytab);

int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);

char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s);
char				*ft_strndup(char const *str, size_t pos, size_t len_words);
char				*ft_strdup_endchar(char *str, char symbol);
char				*ft_str_trimndup(const char *str, size_t start, size_t len);
char				*ft_str_trimndup_echap(const char *str, size_t start,
																	size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *str, char chars);
bool				ft_buff_add_char(char *str, char add, int len);

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_bzero(void *s, size_t n);
void				ft_strclr(char *s);
void				ft_strdel(char **as);

/*
** Transform ASCII Functions
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** IS (bool) Functions
*/
int					ft_isalnum(int c);
int					ft_isalnum_var(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isnumber(char *str);
bool				ft_isalnum_line(char *str);
bool				ft_isprint_line(char *str);
bool				ft_ispace_tab_line(char *str);
bool				ft_is_empty_line(char *line);
bool				ft_isthischar(char *check_symbol, char symbol);
bool				ft_isnthischar(char *check_symbol, char symbol);

/*
** Mem Functions
*/
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t size);
void				ft_memdel(void **ap);

/*
** Free Functions
*/
void				*ft_free_line(char **line);
char				**ft_free_tab(char **mytab);

/*
** List Functions
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
** Files Functions
*/
bool				ft_file_exists(const char *filename);
char				ft_check_typefile(mode_t mode);

/*
** Get_Next_Line
*/
int					get_next_line(int const fd, char **line);

/*
*******************
**	Get_Arg_Opt  **
*******************
** For use it, define *mytab[6] with name, options and error description.
** Then, you have to call the fonction "opt_parse_arguments".
** See the Documentation for more details.
** *
** Comment #define GET_ARG_OPT !! // ne marche pas .. -(
*/
/*
** # define GET_ARG_OPT
*/
# ifndef GET_ARG_OPT
#  define GET_ARG_OPT

typedef struct		s_bool
{
	bool			a;
}					t_bool;

typedef	struct		s_opt
{
	char			**define;
	int				position;
	char			*opt;
	char			*opt_all;
	char			*l_opt;
	int				nb_arg;
	char			**s_arg;
	char			bad_char;
	int				error;
	int				mark;
	struct s_bool	*opt_b;
}					t_opt;

t_opt				*opt_parse_arguments(int argc, char **argv, char **init);
void				opt_get_options(int argc, char **argv, t_opt **e);
void				opt_init_env(t_opt **e, char **init_define);
bool				opt_is_valid(char *str, t_opt **e);
void				opt_exist_letter(char *str, t_opt **e, int i, int a);
bool				opt_exist_long(char *str, t_opt **e);
void				opt_save_arg(char *str, t_opt **e);
void				opt_check_options(t_opt **e);
void				opt_free(t_opt **e);
void				opt_print_error(char **argv, t_opt **e);
int					opt_check_last_opt(char *opt_all, char opt0, char opt1);

/*
**	Endif GET_ARG_OPT
*/
# endif

/*
**	Endif LIBFT_H
*/
#endif
