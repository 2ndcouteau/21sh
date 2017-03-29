/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parsing_std_enter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:01:18 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/11 00:08:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	error_input_shell(t_env **e)
{
	ft_bzero((*e)->command_line, MAX_LEN_COMMAND);
	sh_print_error(1, NULL);
	disable_termcaps();
	return (ERROR);
}

static bool	error_validation_command(t_env **e)
{
	hist_add_new_command(e);
	free_cmd_struct(e);
	free_list_heredoc((*e)->tab_count);
	return (SUCCESS);
}

static bool	valid_command(t_env **e, char **av)
{
	int		ret;

	if (ft_is_empty_line((*e)->command_line))
		return (SUCCESS);
	create_new_cmd_struct(e, (*e)->command_line);
	hist_add_new_command(e);
	if ((ret = (*e)->current_cmd->error_nbr) == 0)
		exec_ast(e, (*e)->current_cmd->begin_list_cut_line, av);
	else
		sh_print_error((*e)->current_cmd->error_nbr,
												(*e)->current_cmd->error_name);
	free_list_heredoc((*e)->tab_count);
	free_cmd_struct(e);
	return (SUCCESS);
}

bool		sh_parsing_std_enter(char **av, t_env **e)
{
	int		ret;

	call_signals();
	ft_putstr(PROMPT);
	if ((ret = sh_get_input((*e)->command_line, e)) == SUCCESS)
		return (valid_command(e, av));
	else if (ret == 2)
		return (error_validation_command(e));
	else
		return (error_input_shell(e));
}
