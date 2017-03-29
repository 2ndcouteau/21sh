/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 22:36:45 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 23:42:27 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <limits.h>
# include <sys/stat.h>
# include <stdio.h>
# include <errno.h>

/*
**	For wait(); function
*/
# include <sys/wait.h>

/*
**	For kill() and signal() functions;
*/
# include <signal.h>

/*
**	For termcaps functions;
*/
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

/*
**	****************************************
**	*********** CUSTOM VARIABLES ***********
**	****************************************
*/

/*
**	Prompt Definition.
*/
# define PROMPT "21SH $$$>> "

/*
**	Historical Limit
**	$$ Can't be inferior to 1.
*/
# define HISTORICAL_LIMIT					500

/*
**	MAX_LEN_COMMAND.
**	$$ Musn't be inferior to 5.
**	*note that the longest executable element of the command have to be inferior
**	of PATH_MAX so <=4096
*/
# define MAX_LEN_COMMAND 					4096

/*
**	****************************************************************************
**	****************************************************************************
**	****************************************************************************
*/

/*
**	****************************************
**	*********** FIXED VARIABLES ************
**	****************************************
*/
# define NB_BUILTIN							8
# define NB_TERM_COMMAND_CURSOR				18
# define NB_TERM_COMMAND_EDITION			6
# define NB_ERROR							5

# define NONE								2

/*
**	******* PONCTUATION DEFINITION ********
*/
# define NB_SPECIAL_SYMBOL					6
# define NB_SPECIAL_DOUBLE_SYMBOL			6

# define NB_SPECIAL_SPLIT_CHAR				15
# define NB_SPECIAL_DUP_SPLIT_SPECIAL_CHAR	11

# define NB_SIGN_EXEC						8

/*
**	Error Input Definition
*/
# define MAX_OPEN_SIGNS						(MAX_LEN_COMMAND - 1) / 2

# define GOOD_ORDER_VALUE					0
# define ERROR_TOO_MANY_OPEN				1

# define ERROR_CLOSE_PARENTHESE				1
# define ERROR_CLOSE_BRACKET				2
# define ERROR_CLOSE_BRACE					4
# define ERROR_NOT_CLOSE_PARENTHESE			5
# define ERROR_NOT_CLOSE_BRACE				6
# define ERROR_NOT_CLOSE_BRACKET			7

/*
**	Value Signs Input mode
*/
# define DIESE								8
# define D_REDICTION_STDIN					16
# define B_QUOTE 							32
# define D_QUOTE 							64
# define QUOTE 								128
# define PARENTHESE 						256
# define SEMI_COLON							512
# define BRACKET 							1024
# define BRACE 								2048

/*
**	Heredoc Statues
*/
# define NO_HEREDOC							0
# define HEREDOC_ACTIVE						1
# define HEREDOC_FINISH						3

/*
**	Value Signs Parser mode
*/
# define VALUE_TOKEN_COMMAND				0
# define VALUE_TOKEN_SEMICOLON				1
# define VALUE_TOKEN_AND					2
# define VALUE_TOKEN_OR						3
# define VALUE_TOKEN_PIPE					4
# define VALUE_TOKEN_OUT_REDIRECTION		5
# define VALUE_TOKEN_IN_REDIRECTION			6
# define VALUE_TOKEN_AGREG_FD				7

/*
**	Redirection Mode
*/
# define SIMPLE_OUT_REDICTION				1
# define DOUBLE_OUT_REDICTION				2

/*
**	Quote Mode
*/
# define MODE_NO_QUOTE						0
# define MODE_SIMPLE_QUOTE					1
# define MODE_DOUBLE_QUOTE					2
# define MODE_BACK_QUOTE					3
# define MODE_BACK_DOUBLE_QUOTE				4

/*
**	****************************************
**	************** STRUCTURES **************
**	****************************************
**
**	***************
**	*** LEXIQUE ***
**	***************
**	*
**	cmd = command;
**	hist = historical;
**	nbr = number;
**	*
**	*********************************
**	Current Command Line Structure	*
**	*********************************
**
**	AST
*/
typedef struct			s_cut_line
{
	char				*command_part;
	int					len_command_part;
	char				*special_char;
	int					len_special_char;
	int					value_token;
	struct s_cut_line	*right;
	struct s_cut_line	*left;
}						t_cut_line;

/*
**	Current Command
*/
typedef struct			s_cmd
{
	char				*line;
	struct s_cut_line	*begin_list_cut_line;
	struct s_cut_line	*last_node_list;
	unsigned int		size_line;
	char				**split_line;
	size_t				size_split_line;
	size_t				nb_order_line;
	char				double_char[3];
	size_t				error_nbr;
	char				*error_name;
	int					value_token;
	int					offset_mark;
}						t_cmd;

/*
**	Historical Session Structure
*/
typedef struct			s_hist
{
	unsigned int		index;
	char				*command_line;
	struct s_hist		*next;
	struct s_hist		*prev;
}						t_hist;

/*
**	Historical Copy Session Structure
*/
typedef struct			s_c_hist
{
	unsigned int		index;
	char				line[MAX_LEN_COMMAND];
	struct s_c_hist		*next;
	struct s_c_hist		*prev;
}						t_c_hist;

/*
**	Position Cursor Structure
*/
typedef struct			s_position
{
	struct s_c_hist		*current_history;
	struct s_c_hist		*copy_hist_begin;
	char				ptr_new_tmp[MAX_LEN_COMMAND];
	char				buffer_line[MAX_LEN_COMMAND];
	char				buffer_copy[MAX_LEN_COMMAND];
	int					len_prompt;
	int					len_command;
	bool				heredoc_active;
	int					len_full_command;
	int					absolute_pos;
	int					x;
	int					y;
	int					x_end;
	int					y_end;
	int					x_win;
	int					y_win;
	bool				waiting_mode;
}						t_position;

/*
**	List Words Heredoc
*/
typedef struct			s_heredoc
{
	char				*word;
	char				*save_text;
	struct s_heredoc	*next;
}						t_heredoc;

/*
**	Count Element Lexer-Parser
*/
typedef struct			s_count
{
	int					status;
	char				order_line[MAX_LEN_COMMAND / 2];
	int					order_position;
	int					len_waiting_prompt;
	bool				pass;
	bool				trim_space;
	int					heredoc_mode;
	int					position_last_heredoc_word;
	bool				heredoc_active;
	struct s_heredoc	*begin_list_heredoc;
	struct s_heredoc	*check_position_heredoc;
	struct s_heredoc	*last_word_heredoc;
	bool				back_slash;
	bool				diese;
	int					parentheses;
	int					brackets;
	int					braces;
	bool				error;
}						t_count;

/*
**	Global Environnement Structure
*/
typedef struct			s_env
{
	struct s_position	*posicao;
	struct s_count		*tab_count;
	struct s_cmd		*current_cmd;
	struct s_hist		*historical;
	char				command_line[MAX_LEN_COMMAND];
	int					size_env;
	char				**env;
	char				**original_env;
}						t_env;

/*
**	Tableaux de pointeurs sur fonctions
*/
char					(*g_builtins[NB_BUILTIN])
									(t_env **e);
bool					(*g_term_command_edition[NB_TERM_COMMAND_EDITION])
									(t_env **e, char **new_tmp);
bool					(*g_term_command_cursor[NB_TERM_COMMAND_CURSOR])
									(t_env **e, char **new_tmp);
int						(*g_check_previous_symbols[NB_SPECIAL_SYMBOL])
									(t_count *tab_count);
int						(*g_check_previous_double_symbols
								[NB_SPECIAL_DOUBLE_SYMBOL])(t_count *tab_count);
char					(*g_exec_sign_functions[NB_SIGN_EXEC])
									(t_env **e, t_cut_line *list, char **av);

/*
**	****************************************
**	*********** SHELL FUNCTIONS ************
**	****************************************
**
**	Main Functions
*/
int						main(int ac, char **av, char **env);
bool					sh_parsing_std_enter(char **av, t_env **e);
void					sh_start_endless_loop(char **av, char **env);

/*
**	General Functions
*/
void					print_prompt_sig(int sig);
char					check_typefile(mode_t mode);
bool					sh_add_end_path(char **current_pwd, char *add_elem,
	int pwd_len);
void					sh_special_putstr(char *str);
void					call_signals(void);
void					call_sub_signals(void);
t_env					*singleton_t_env(t_env *env);

/*
**	System Exec Command
*/
char					exec_ast(t_env **e, t_cut_line *list, char **av);
char					exec_system_cmd(t_env **e, char **av);
char					exec_command_for_env(t_env **e, char **av);
bool					exec_check_path(t_env **e, char **path);
char					exec_builtins(t_env **e);
int						exec_return_status(int status);

/*
**	System Exec Command
*/
char					exec_command(t_env **e, t_cut_line *list, char **av);
char					exec_default(t_env **e, t_cut_line *list, char **av);
char					exec_semi_colon(t_env **e, t_cut_line *list,
	char **av);
char					exec_and(t_env **e, t_cut_line *list, char **av);
char					exec_or(t_env **e, t_cut_line *list, char **av);
char					exec_pipe(t_env **e, t_cut_line *list, char **av);
char					exec_redirection(t_env **e, t_cut_line *list,
	char **av);
char					exec_heredoc(t_env **e, t_cut_line *list, char **av);
void					free_node_heredoc(t_env **e);
char					exec_agreg_fd(t_env **e, t_cut_line *list, char **av);
bool					error_fork_output(void);
char					error_pipe_output(void);
int						browse_search_last_fd(t_cut_line *list, char mode);

/*
**	Split Command Parts Functions
*/
char					**split_clean_command(t_env **e, char *command);
int						count_len_variable_name(char *str);
int						count_word_len(t_env **e, char *str, int i,
															int *offset_cmd);
int						check_quote_mode(char *str, int i, char *mode,
																int len_total);
int						count_nb_words(char *command);
char					*dup_and_replace(t_env **e, char *command, int i,
																int len_word);
int						check_quote_mode_dup(char *command, char *mode_quote,
																		int i);

/*
**	Historical Functions
*/
void					hist_list_push_front_struct(t_env **e);
void					hist_list_push_front_max(t_env **e);
void					hist_add_new_command(t_env **e);

/*
**	Input Functions
*/
int						sh_get_input(char *command_line, t_env **e);
bool					create_new_env(t_env **e, char **env);
void					create_new_cmd_struct(t_env **e, char *command_line);
bool					create_path_name(t_env **e, t_opt **cd_opt,
	char **current_pwd);

/*
**	****************************************
**	******* LEXER-PARSER FUNCTIONS *********
**	****************************************
**
**	Generals Functions
*/
int						lexpar_check_main(t_env **e, char *command_line,
												char *buffer_line, int start);
void					init_tab_count(t_count *tab_count);
void					init_tab_count_new_command(t_count *tab_count);
int						check_special_symbols(char symbol);
int						check_special_double_symbols(char symbol);
void					check_words_key(t_position *posicao, t_count *tab_count,
													char *command_line, int i);
int						count_offset_redirection_name(t_env **e,
	char *command_line, int pos_line, int pos_word);
void					print_waiting_prompt(t_count *tab_count, bool jump);
bool					print_heredocs(t_count *tab_count);
bool					print_double_quote(t_count *tab_count);
bool					print_parenthese_brace_bracket(t_count *tab_count);
bool					error_status(t_env **e);
bool					error_check(int status, int heredoc_mode);
t_count					*singleton_t_count(t_count *tab_count);

/*
**	Check Double_redirection Functions
*/
void					add_new_heredoc_word(t_count *tab_count,
	char *command_line, int i);
void					dup_heredoc_word(t_count *tab_count,
	char *command_line, int i);
void					check_buffer_line_for_heredoc(t_env **e,
	t_count *tab_count, char *buffer_line);
char					*lexpar_str_add_join(char *dst, char *src);

/*
**	Check Symbols Functions
*/

void					check_diese(t_count *tab_count, char *command_line,
	int i);
void					check_double_redirection_stdin(t_env **e, t_count
										*tab_count, char *command_line, int i);
int						check_andcmd(t_count *tab_count, char *command_line,
	int i);
void					check_space_tab_n(t_count *tab_count);

bool					check_active_condition(t_count *tab_count);

int						check_quote(t_count *tab_count);
int						check_double_quote(t_count *tab_count);
int						check_back_quote(t_count *tab_count);
int						check_major(t_count *tab_count);
int						check_semi_colon(t_count *tab_count);
int						check_pipe(t_count *tab_count);

int						check_open_parenthese(t_count *tab_count);
int						check_close_parenthese(t_count *tab_count);
int						check_open_brace(t_count *tab_count);
int						check_close_brace(t_count *tab_count);
int						check_open_bracket(t_count *tab_count);
int						check_close_bracket(t_count *tab_count);

/*
************
**	Split Line Functions
************
*/
void					lexer_parser_split_line_in_list(t_env **e,
															char *command_line);
bool					is_special_split_char(char *command_line, int start,
										t_cmd *current_cmd, int *heredoc_mode);
void					add_suppr_double_char(char *double_char,
												char *command_line, int start);
bool					check_back_slash(char *command_line, int start);
bool					check_empty_command_node(char *command_line,
	int pos_line, int pos_word);
void					create_command_node(t_env **e, char *command_line,
	int pos_line, int pos_word);
int						create_special_char_node(t_env **e, char *command_line,
	int pos_line, int pos_word);

/*
**	Dup Check Special Char
*/
char					*lxp_dup_special_char(t_env **e, char *command_line,
	int pos_line, int pos_word);
char					*check_second_pipe(t_env **e, char *command_line,
	int start);
char					*check_second_semicolon(t_env **e, char *command_line,
	int start);
char					*check_second_minor(t_env **e, char *command_line,
	int start);
char					*check_second_major(t_env **e, char *command_line,
	int pos_line, int pos_word);
char					*check_second_major_double(t_env **e,
	char *command_line, int start);
char					*check_second_andco(t_env **e, char *command_line,
	int start);
bool					is_cmdand(char *command_line, int start);
char					*split_agregator_fd(t_env **e, char *command_line,
	int pos_line, int pos_word);

/*
**	AST - Abstract Syntax Tree
*/
t_cut_line				*clean_list(t_cut_line *begin_list);
t_cut_line				*remove_double_part(t_cut_line *begin_list);
t_cut_line				*create_ast(t_env **e, t_cut_line *list, int level);
t_cut_line				*free_node_list(t_cut_line *node);
t_cut_line				*sort_command_line(t_cut_line *begin_list);
void					move_node_command_part(t_cut_line **browse_tmp,
								t_cut_line **relay_tmp, t_cut_line **begin_tmp);
bool					check_new_cmd(t_cut_line *browse_tmp);
void					join_all_command_part(t_cut_line **relay_tmp);
void					sort_input_redirection(t_cut_line **relay_tmp);
void					sort_agreg_fd(t_cut_line **relay_tmp);

/*
**	****************************************
**	*************** TERMCAPS ***************
**	****************************************
*/

/*
**	Termcaps Values
*/
# define ENTER								10

/*
**	Termcaps Functions
*/
int						init_termcaps(char **env);
bool					enable_termcaps(void);
int						disable_termcaps(void);
bool					term_get_input(char *buffer);
bool					term_check_input(t_env **e, char *buffer,
	char *new_tmp);
bool					put_stdout(char *opt);
void					term_putstr(t_position *posicao, char **new_tmp);
void					term_str_add_cpy(t_env **e, char *dst);
void					suppr_back_slash(char *command_line,
	t_position *posicao, t_count *tab_count);
void					replace_cursor_window(int sig);
void					init_and_set_struct_for_input(char *command_line,
																	t_env **e);
void					reinitialisation_posicao(t_env **e);
void					reinitialisation_posicao_waiting_mode(
	t_position *posicao, t_count *tab_count);
t_position				*singleton_t_posicao(t_position *posicao);

/*
**	Termcaps Tools Functions
*/
void					term_set_cursor_position(t_position *posicao);
void					x_write_position(t_position *posicao);
void					x_less_position(t_position *posicao);
void					x_more_position(t_position *posicao);
void					x_suppr_position(t_position *posicao);
void					x_del_position(t_position *posicao);
void					replace_cursor(t_position *posicao);
void					x_first_column(t_position *posicao);
void					x_last_column(void);

/*
**	Termcaps Command General Functions
*/
bool					exec_term_command(char *buffer, t_position *posicao,
																char **new_tmp);
bool					exec_term_add_caractere(char *buffer,
							long int *buff_convert, t_env **e, char *new_tmp);
bool					exec_term_command_cursor(long int *buff_convert,
	t_env **e, char **new_tmp);
bool					exec_term_command_edition(long int *buff_convert,
	t_env **e, char **new_tmp);
bool					ctrl_d(t_env **e, char **new_tmp);
bool					ctrl_l(t_env **e, char **new_tmp);
bool					ctrl_k(t_env **e, char **new_tmp);
bool					ctrl_u(t_env **e, char **new_tmp);
bool					ctrl_y(t_env **e, char **new_tmp);

/*
**	Termcaps Command Cursor Functions
*/
bool					ctrl_a(t_env **e, char **new_tmp);
bool					ctrl_e(t_env **e, char **new_tmp);
bool					arrow_right(t_env **e, char **new_tmp);
bool					arrow_left(t_env **e, char **new_tmp);
bool					alt_up(t_env **e, char **new_tmp);
bool					alt_down(t_env **e, char **new_tmp);
bool					alt_right(t_env **e, char **new_tmp);
bool					alt_left(t_env **e, char **new_tmp);

/*
**	Termcaps Command Edition Functions
*/
bool					echap(t_env **e, char **new_tmp);
bool					suppr(t_env **e, char **new_tmp);
bool					del(t_env **e, char **new_tmp);

/*
**	Termcaps History Functions
*/
bool					arrow_up(t_env **e, char **new_tmp);
bool					arrow_down(t_env **e, char **new_tmp);
void					term_copy_hist_list(t_env **e);
void					free_copy_hist_list(t_env **e);

/*
**	****************************************
**	*************** BUILTINS ***************
**	****************************************
**
**	Builtins
*/
char					cd_builtin(t_env **e);
char					env_builtin(t_env **e);
char					setenv_builtin(t_env **e);
char					unsetenv_builtin(t_env **e);
char					exit_builtin(t_env **e);
char					envreset_builtin(t_env **e);
char					history_builtin(t_env **e);
char					echo_builtin(t_env **e);

/*
**	Echo Options definition
*/

# define LEN_ECHO_SPECIAL_CHAR				10
# define ECHO_SPECIAL_CHAR					"\\abefnrtvc"
# define ECHO_CONVERT_CHAR					"\\\a\b\e\f\n\r\t\v"

/*
**	Env Builtins Functions
*/
int						env_position_line(t_env **e, char *var_e, int len);
void					env_replace_var(char **env, char *variable, char *value,
	int position);
char					**save_env_fct(t_env **e);
char					**restore_env(t_env **e, char **save_env);
void					print_env(t_env **e);
int						check_tmp_var(t_env **e, int cpt);
char					exec_without_option(t_env **e);
char					exec_with_option(t_env **e);
void					set_new_var(t_env **e, int ret, int cpt);

/*
**	Setenv Builtins Functions
*/
int						setenv_var(t_env **e, char *var_env, char *value);

/*
**	CD Builtins Functions
*/
void					cd_create_path_name(t_env **e, t_opt **cd_opt,
	char **current_pwd);
bool					cd_check_valid_file(t_env **e, char **current_pwd,
	char *name);
void					cd_set_error(t_env **e, char *name, int nbr);
int						cd_check_new_path(char *new_path);
void					cd_oldpwd(t_env **e, char **current_pwd);
void					cd_home(t_env **e, char **current_pwd, char *new_path);
void					cd_relative_path(t_env **e, char **current_pwd,
	char *new_path);
void					cd_absolute_path(t_env **e, char **current_pwd,
	char *new_path);
void					cd_swap_pwd_env(t_env **e, char **current_pwd,
	t_opt **cd_opt);
void					cd_clean_path(char **current_pwd);

/*
**	Echo Builtins Functions
*/
void					print_echo_line(t_env **e, unsigned int tab_position,
																short options);
void					print_direct_line(t_env **e, unsigned int tab_position,
																short options);
bool					print_special_line(t_env **e, unsigned int tab_position,
																short options);
bool					print_long_options(short options);
short					check_option_echo(t_env **e, short *options);
void					set_option(char *word, short *options);
bool					is_valid_option(char *word, int size_tab);
int						convert_hex_octal_to_char(char *str, int i);

/*
**	****************************************
**	************ FREE FUNCTIONS ************
**	****************************************
**
**	Free Functions
*/
void					free_cmd_struct(t_env **e);
void					free_posicao_struct(t_env **e);
void					free_historical(t_hist *tmp);
void					free_tab_count(t_env **e);
void					free_list_heredoc(t_count *tab_count);
void					env_free_cmd(t_env **e);
void					free_all_env(t_env **e);
void					env_free_all_env(t_env **e);

/*
**	****************************************
**	*********** ERROR FUNCTIONS ************
**	****************************************
**
**	Print Error Functions
*/
void					sh_print_error(int error, char *name);
void					exec_print_error(int error, char *name);
void					cd_print_error(int error, char *name);

#endif
