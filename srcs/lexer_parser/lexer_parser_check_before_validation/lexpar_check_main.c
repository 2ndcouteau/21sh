/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexpar_check_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:58:07 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:39:30 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	loop_check(char *command_line, int i, t_env **e,
																int position)
{
	if ((*e)->tab_count->back_slash == 0)
	{
		if (command_line[i] == 92)
			(*e)->tab_count->back_slash = 1;
		else if ((position = check_special_symbols(command_line[i])) != -1)
			(*e)->tab_count->status +=
							g_check_previous_symbols[position]((*e)->tab_count);
		else if ((position =
						check_special_double_symbols(command_line[i])) != -1)
			(*e)->tab_count->status +=
					g_check_previous_double_symbols[position]((*e)->tab_count);
		else if (command_line[i] == '<')
			check_double_redirection_stdin(e, (*e)->tab_count, command_line, i);
		else if (command_line[i] == '&')
			check_andcmd((*e)->tab_count, command_line, i);
		else if (command_line[i] == '#')
			check_diese((*e)->tab_count, command_line, i);
		else if (command_line[i] == ' ' || command_line[i] == '\t' ||
														command_line[i] == '\n')
			check_space_tab_n((*e)->tab_count);
		else
			(*e)->tab_count->trim_space = 1;
	}
	else
		(*e)->tab_count->back_slash = 0;
}

bool		check_special_value(int status)
{
	if ((status & DIESE) != DIESE)
		return (SUCCESS);
	return (ERROR);
}

static void	set_pass_and_last_heredoc_word(t_env **e, int i)
{
	if ((*e)->tab_count->pass == 0 &&
								(*e)->tab_count->heredoc_mode == HEREDOC_ACTIVE)
	{
		(*e)->tab_count->pass = 1;
		(*e)->tab_count->position_last_heredoc_word = i;
	}
}

static int	check_buffer_line_for_normal_usage(t_env **e, char *command_line,
																	int start)
{
	int		i;

	i = 0;
	if ((*e)->tab_count->heredoc_mode != HEREDOC_FINISH)
		init_tab_count((*e)->tab_count);
	else
	{
		i = start;
		(*e)->tab_count->back_slash = 0;
	}
	while (command_line[i] != '\0' &&
								!check_special_value((*e)->tab_count->status))
	{
		if (!error_check((*e)->tab_count->status,
												(*e)->tab_count->heredoc_mode))
			loop_check(command_line, i, e, 0);
		i++;
	}
	return (i);
}

int			lexpar_check_main(t_env **e, char *command_line, char *buffer_line,
																	int start)
{
	int		i;

	i = 0;
	if ((*e)->tab_count->heredoc_mode != HEREDOC_ACTIVE)
		i = check_buffer_line_for_normal_usage(e, command_line, start);
	else
		check_buffer_line_for_heredoc(e, (*e)->tab_count, buffer_line);
	set_pass_and_last_heredoc_word(e, i);
	if (!error_status(e))
		return (2);
	if ((((*e)->tab_count->status == 0 || ((*e)->tab_count->status & DIESE)
				== DIESE)) && (*e)->tab_count->heredoc_active != HEREDOC_ACTIVE)
		return (SUCCESS);
	else
		return ((*e)->tab_count->status);
}
