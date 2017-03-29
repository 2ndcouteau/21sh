/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_check_second_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 19:18:22 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:51:50 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	check_error_pipe_double(t_env **e, char *command_line, int start)
{
	int i;

	i = 2;
	while (command_line[start + i] == ' ' || command_line[start + i] == '\t' ||
												command_line[start + i] == '\n')
		i++;
	if (!ft_isthischar(";|", command_line[start + i]) || command_line[start + i]
							== '\0' || !is_cmdand(command_line, (start + i)))
	{
		if (command_line[start + i] == ';')
			(*e)->current_cmd->error_name = ft_strdup(";");
		else if (command_line[start + i] == '|')
			(*e)->current_cmd->error_name = ft_strdup("|");
		else if (command_line[start + i] == '\0')
			(*e)->current_cmd->error_name = ft_strdup("newline");
		else
			(*e)->current_cmd->error_name = ft_strdup("&&");
		(*e)->current_cmd->error_nbr = -2;
		return (0);
	}
	return (1);
}

static bool	check_error_pipe(t_env **e, char *command_line, int start)
{
	int i;

	i = 1;
	while (command_line[start + i] == ' ' || command_line[start + i] == '\t' ||
												command_line[start + i] == '\n')
		i++;
	if (command_line[start + i] == ';' || command_line[start + i] == '\0' ||
										!is_cmdand(command_line, (start + i)))
	{
		if (command_line[start + i] == ';')
			(*e)->current_cmd->error_name = ft_strdup(";");
		else if (command_line[start + i] == '\0')
			(*e)->current_cmd->error_name = ft_strdup("newline");
		else
			(*e)->current_cmd->error_name = ft_strdup("&&");
		(*e)->current_cmd->error_nbr = -2;
		return (0);
	}
	return (1);
}

static char	*check_third_pipe(t_env **e, char *command_line, int start)
{
	if (!check_error_pipe_double(e, command_line, start))
		return (ft_strdup("\0"));
	(*e)->current_cmd->value_token = VALUE_TOKEN_OR;
	return (ft_strdup("||"));
}

char		*check_second_pipe(t_env **e, char *command_line, int start)
{
	if (command_line[start + 1] == '|')
		return (check_third_pipe(e, command_line, start));
	if (!check_error_pipe(e, command_line, start))
		return (ft_strdup("\0"));
	(*e)->current_cmd->value_token = VALUE_TOKEN_PIPE;
	return (ft_strdup("|"));
}
