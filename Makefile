# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:46:25 by qrosa             #+#    #+#              #
#    Updated: 2017/02/10 15:56:10 by qrosa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#																			   #
#   					-- MAKEFILE for 21SH project --						   #
#																			   #
################################################################################

#	ROOT_PATH && DIRECTORIES
PATH_SOURCES	=		./srcs/

PATH_TERMCAPS			=	$(PATH_SOURCES)termcaps/
PATH_ENV				=	$(PATH_SOURCES)env/
PATH_LEXPAR				=	$(PATH_SOURCES)lexer_parser/
PATH_EXECUTION			=	$(PATH_SOURCES)execution/
PATH_BUILTINS			=	$(PATH_SOURCES)builtins/
PATH_HISTORY			=	$(PATH_SOURCES)history/
PATH_FREE				=	$(PATH_SOURCES)free/

#	PATH Exec_Functions
PATH_EXEC_FCT			=	$(PATH_EXECUTION)exec_functions/

#	PATH Split_command_parts
PATH_SPLIT_CMD			=	$(PATH_EXEC_FCT)split_command_parts/

#	PATH BUILTINS
PATH_CD					=	$(PATH_BUILTINS)cd/
PATH_ECHO				=	$(PATH_BUILTINS)echo/
PATH_ENV_BUILTIN		=	$(PATH_BUILTINS)env_builtin/

#	PATH Lexer_Parser
PATH_MAIN_CHECK_SYMB	= 	$(PATH_LEXPAR)lexer_parser_check_before_validation/
PATH_SPLIT_LINE 		=	$(PATH_LEXPAR)lexer_parser_split_after_validation/
PATH_AST				=	$(PATH_LEXPAR)AST/

PATH_CHECK_SYMB			=	$(PATH_MAIN_CHECK_SYMB)check_symbols/

################################################################################

#	FILES DECLARATIONS
SRCS			=	$(PATH_SOURCES)main.c\
					$(PATH_SOURCES)sh_start_endless_loop.c\
					$(PATH_SOURCES)sh_parsing_std_enter.c\
					$(PATH_SOURCES)sh_print_error.c\
					$(PATH_SOURCES)sh_get_input.c\
					$(PATH_SOURCES)sh_create_new_cmd_struct.c\
					$(PATH_SOURCES)sh_add_end_path.c\
					$(PATH_SOURCES)sh_special_putstr.c\
					$(PATH_SOURCES)sh_call_signals.c\
					$(PATH_SOURCES)singleton_t_env.c

SRCS_TERMCAPS	=	$(PATH_TERMCAPS)termcaps.c\
					$(PATH_TERMCAPS)term_check_input.c\
					$(PATH_TERMCAPS)term_get_input.c\
					$(PATH_TERMCAPS)term_put_stdout.c\
					$(PATH_TERMCAPS)term_putstr.c\
					$(PATH_TERMCAPS)term_exec_add_caractere.c\
					$(PATH_TERMCAPS)term_exec_command_cursor.c\
					$(PATH_TERMCAPS)term_exec_command_edition.c\
					$(PATH_TERMCAPS)term_home_end.c\
					$(PATH_TERMCAPS)term_alt_move_line.c\
					$(PATH_TERMCAPS)term_alt_move_word.c\
					$(PATH_TERMCAPS)term_arrow_history.c\
					$(PATH_TERMCAPS)term_arrow_move_cursor.c\
					$(PATH_TERMCAPS)term_tools_functions.c\
					$(PATH_TERMCAPS)term_suppr_caractere.c\
					$(PATH_TERMCAPS)term_del_caractere.c\
					$(PATH_TERMCAPS)term_x_count_move_position.c\
					$(PATH_TERMCAPS)term_x_first_last_position.c\
					$(PATH_TERMCAPS)term_ctrl_l.c\
					$(PATH_TERMCAPS)term_ctrl_k.c\
					$(PATH_TERMCAPS)term_ctrl_u.c\
					$(PATH_TERMCAPS)term_ctrl_y.c\
					$(PATH_TERMCAPS)term_ctrl_d.c\
					$(PATH_TERMCAPS)term_echap.c\
					$(PATH_TERMCAPS)term_replace_cursor.c\
					$(PATH_TERMCAPS)term_copy_hist_list.c\
					$(PATH_TERMCAPS)term_suppr_back_slash.c\
					$(PATH_TERMCAPS)term_set_cursor_position.c\
					$(PATH_TERMCAPS)term_replace_cursor_window.c\
					$(PATH_TERMCAPS)term_str_add_copy.c\
					$(PATH_TERMCAPS)struct_reinitialisation_posicao.c\
					$(PATH_TERMCAPS)struct_reinitialisation_posicao_waiting_mode.c\
					$(PATH_TERMCAPS)singleton_t_posicao.c

SRCS_ENV		=	$(PATH_ENV)env_position_line.c\
					$(PATH_ENV)env_replace_var.c\
					$(PATH_ENV)env_free_all_env.c\
					$(PATH_ENV)sh_free_all_env.c\
					$(PATH_ENV)sh_create_new_env.c

SRCS_LEXPAR		=	$(PATH_MAIN_CHECK_SYMB)lexpar_check_main.c\
					$(PATH_MAIN_CHECK_SYMB)lexpar_print_waiting_prompt.c\
					$(PATH_MAIN_CHECK_SYMB)lexpar_check_special_symbols.c\
					$(PATH_MAIN_CHECK_SYMB)lexpar_check_special_double_symbols.c\
					$(PATH_MAIN_CHECK_SYMB)lexpar_init_tab_count.c\
					$(PATH_MAIN_CHECK_SYMB)lexpar_error_management.c\
					$(PATH_MAIN_CHECK_SYMB)lexpar_str_add_join.c\
					$(PATH_MAIN_CHECK_SYMB)check_add_new_heredoc_word.c\
					$(PATH_MAIN_CHECK_SYMB)check_dup_heredoc_word.c\
					$(PATH_MAIN_CHECK_SYMB)check_buffer_line_for_heredoc.c\
					$(PATH_MAIN_CHECK_SYMB)lexpar_init_tab_count_new_command.c\
					$(PATH_MAIN_CHECK_SYMB)print_parenthese_brace_bracket.c\
					$(PATH_MAIN_CHECK_SYMB)print_double_quote.c\
					$(PATH_MAIN_CHECK_SYMB)print_heredocs.c\
					$(PATH_MAIN_CHECK_SYMB)singleton_tab_count.c

SRCS_CHECK_SYMB	=	$(PATH_CHECK_SYMB)check_active_condition.c\
					$(PATH_CHECK_SYMB)check_quote.c\
					$(PATH_CHECK_SYMB)check_double_quote.c\
					$(PATH_CHECK_SYMB)check_back_quote.c\
					$(PATH_CHECK_SYMB)check_diese.c\
					$(PATH_CHECK_SYMB)check_open_parenthese.c\
					$(PATH_CHECK_SYMB)check_open_brace.c\
					$(PATH_CHECK_SYMB)check_open_bracket.c\
					$(PATH_CHECK_SYMB)check_close_parenthese.c\
					$(PATH_CHECK_SYMB)check_close_brace.c\
					$(PATH_CHECK_SYMB)check_close_bracket.c\
					$(PATH_CHECK_SYMB)check_semi_colon.c\
					$(PATH_CHECK_SYMB)check_pipe.c\
					$(PATH_CHECK_SYMB)check_major.c\
					$(PATH_CHECK_SYMB)check_andcmd.c\
					$(PATH_CHECK_SYMB)check_space_tab_n.c\
					$(PATH_CHECK_SYMB)check_double_redirection_stdin.c

SRCS_SPLIT_LINE	=	$(PATH_SPLIT_LINE)lexer_parser_split_line.c\
					$(PATH_SPLIT_LINE)lxp_is_special_split_char.c\
					$(PATH_SPLIT_LINE)add_suppr_double_char.c\
					$(PATH_SPLIT_LINE)lxp_check_back_slash.c\
					$(PATH_SPLIT_LINE)lxp_create_command_node.c\
					$(PATH_SPLIT_LINE)check_emtpy_command_node.c\
					$(PATH_SPLIT_LINE)count_offset_redirection_mode.c\
					$(PATH_SPLIT_LINE)lxp_dup_special_char.c\
					$(PATH_SPLIT_LINE)lxp_create_special_char_node.c\
					$(PATH_SPLIT_LINE)lxp_check_second_semicolon.c\
					$(PATH_SPLIT_LINE)lxp_check_second_pipe.c\
					$(PATH_SPLIT_LINE)lxp_check_second_major.c\
					$(PATH_SPLIT_LINE)lxp_check_second_minor.c\
					$(PATH_SPLIT_LINE)lxp_check_second_andco.c\
					$(PATH_SPLIT_LINE)lxp_is_cmdand.c\
					$(PATH_SPLIT_LINE)lxp_split_agregator_fd.c

SRCS_AST		=	$(PATH_AST)clean_list.c\
					$(PATH_AST)remove_double_part.c\
					$(PATH_AST)create_ast.c\
					$(PATH_AST)free_node_list.c\
					$(PATH_AST)sort_command_line.c\
					$(PATH_AST)move_node_command_part.c\
					$(PATH_AST)join_all_command_part.c\
					$(PATH_AST)check_new_cmd.c\
					$(PATH_AST)sort_input_redirection.c\
					$(PATH_AST)sort_agreg_fd.c\

SRCS_EXECUTION	=	$(PATH_EXECUTION)exec_ast.c\
					$(PATH_EXECUTION)exec_command_for_env.c\
					$(PATH_EXECUTION)exec_system_cmd.c\
					$(PATH_EXECUTION)exec_check_path.c\
					$(PATH_EXECUTION)exec_print_error.c\
					$(PATH_EXECUTION)exec_builtins.c\
					$(PATH_EXECUTION)exec_return_status.c\

SRCS_SPLIT_CMD	=	$(PATH_SPLIT_CMD)split_clean_command.c\
					$(PATH_SPLIT_CMD)count_len_variable_name.c\
					$(PATH_SPLIT_CMD)count_word_len.c\
					$(PATH_SPLIT_CMD)check_quote_mode.c\
					$(PATH_SPLIT_CMD)count_nb_words.c\
					$(PATH_SPLIT_CMD)dup_and_replace.c\
					$(PATH_SPLIT_CMD)check_quote_mode_dup.c\

SRCS_EXEC_FCT	=	$(PATH_EXEC_FCT)exec_command.c\
					$(PATH_EXEC_FCT)exec_semi_colon.c\
					$(PATH_EXEC_FCT)exec_and.c\
					$(PATH_EXEC_FCT)exec_or.c\
					$(PATH_EXEC_FCT)exec_default.c\
					$(PATH_EXEC_FCT)exec_pipe.c\
					$(PATH_EXEC_FCT)exec_redirection.c\
					$(PATH_EXEC_FCT)exec_heredoc.c\
					$(PATH_EXEC_FCT)exec_agreg_fd.c\
					$(PATH_EXEC_FCT)error_fork_output.c\
					$(PATH_EXEC_FCT)error_pipe_output.c\
					$(PATH_EXEC_FCT)browse_search_last_fd.c\

SRCS_BUILTINS	=	$(PATH_BUILTINS)builtin_env.c\
					$(PATH_BUILTINS)builtin_setenv.c\
					$(PATH_BUILTINS)builtin_unsetenv.c\
					$(PATH_BUILTINS)builtin_envreset.c\
					$(PATH_BUILTINS)builtin_history.c\
					$(PATH_BUILTINS)builtin_exit.c\
					$(PATH_BUILTINS)builtin_cd.c\
					$(PATH_BUILTINS)builtin_echo.c\

SRCS_CD			=	$(PATH_CD)cd_swap_pwd_env.c\
					$(PATH_CD)cd_clean_path.c\
					$(PATH_CD)cd_create_path_name.c\
					$(PATH_CD)cd_check_valid_file.c\
					$(PATH_CD)cd_set_error.c\
					$(PATH_CD)cd_oldpwd.c\
					$(PATH_CD)cd_home.c\
					$(PATH_CD)cd_absolute_path.c\
					$(PATH_CD)cd_relative_path.c\
					$(PATH_CD)cd_check_new_path.c\
					$(PATH_CD)cd_print_error.c

SRCS_ECHO		=	$(PATH_ECHO)check_option_echo.c\
					$(PATH_ECHO)check_option_is_valid.c\
					$(PATH_ECHO)check_option_set.c\
					$(PATH_ECHO)print_direct_line.c\
					$(PATH_ECHO)print_echo_line.c\
					$(PATH_ECHO)print_long_options.c\
					$(PATH_ECHO)print_special_line.c\
					$(PATH_ECHO)convert_hex_octal_to_char.c

SRCS_ENV_BUILTIN=	$(PATH_ENV_BUILTIN)set_new_var.c\
					$(PATH_ENV_BUILTIN)exec_with_option.c\
					$(PATH_ENV_BUILTIN)exec_without_option.c\
					$(PATH_ENV_BUILTIN)print_env.c\
					$(PATH_ENV_BUILTIN)restore_env.c\
					$(PATH_ENV_BUILTIN)save_env_fct.c\
					$(PATH_ENV_BUILTIN)check_tmp_var.c

SRCS_HISTORY	=	$(PATH_HISTORY)hist_add_new_command.c\
					$(PATH_HISTORY)hist_list_push_front.c

SRCS_FREE		=	$(PATH_FREE)free_struct.c\
					$(PATH_FREE)free_tab_count.c

################################################################################

#	Object Rules Declarations
OBJ			=	$(SRCS:.c=.o)\
				$(SRCS_TERMCAPS:.c=.o)\
				$(SRCS_LEXPAR:.c=.o)\
				$(SRCS_CHECK_SYMB:.c=.o)\
				$(SRCS_SPLIT_LINE:.c=.o)\
				$(SRCS_AST:.c=.o)\
				$(SRCS_EXECUTION:.c=.o)\
				$(SRCS_EXEC_FCT:.c=.o)\
				$(SRCS_SPLIT_CMD:.c=.o)\
				$(SRCS_ENV:.c=.o)\
				$(SRCS_BUILTINS:.c=.o)\
				$(SRCS_CD:.c=.o)\
				$(SRCS_ECHO:.c=.o)\
				$(SRCS_ENV_BUILTIN:.c=.o)\
				$(SRCS_HISTORY:.c=.o)\
				$(SRCS_FREE:.c=.o)

# Lib includes
INC			=	-I ./includes/
LIBFT		=	libft/libft.a
LFT			=	-L ./libft/ -lft

# Options can be changed
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS_OBJ	=	-Wall -Wextra -Werror
TERMCAPS	=	-lncurses
CC			=	gcc
NAME		=	21sh

# Sweet colors just for swag :)
RED			=	\033[0;31m
BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
YELLOW		=	\033[0;33m
GREEN		=	\033[1;32m
NC			=	\033[0m

################################################################################

#	Make Rules
all: 			$(LIBFT) $(NAME)

debug:
				$(eval CFLAGS_OBJ += -DDEBUG)

db: 			debug all

$(LIBFT):
				@make -C libft

$(NAME): 		$(OBJ) libft/ Makefile
				@echo "${BLUE}-- Linking $(NAME)${NC}"
				@$(CC) $(OBJ) $(CFALGS) -o $(NAME) $(INC) $(LFT) $(TERMCAPS)

%.o: %.c
				@echo "${CYAN}Compiling $^ into $@ ${NC}";
				@$(CC) -g -c $^ -o $@ $(CFLAGS_OBJ) $(INC)

clean:
				@make clean -C libft
				@echo "${YELLOW}-- Delete ft_ls/libft	Objects OK ${NC}";
				@rm -f $(OBJ)

fclean: 		clean
				@echo "${RED}-- Remove $(LIBFT)		OK${NC}"
				@rm -f $(LIBFT)
				@echo "${RED}-- Remove $(NAME)			OK${NC}"
				@rm -f $(NAME)

re: 			fclean all

rdb: 			fclean db

.PHONY: 		all clean fclean re db rdb
