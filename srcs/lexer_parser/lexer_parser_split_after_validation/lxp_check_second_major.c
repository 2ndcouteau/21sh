/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_check_second_major.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 19:16:51 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:50:46 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	check_error_major_double(t_env **e, char *command_line, int start)
{
	int	i;

	i = 2;
	while (command_line[start + i] == ' ' || command_line[start + i] == '\t' ||
												command_line[start + i] == '\n')
		i++;
	if (!ft_isthischar(";|><({[", command_line[start + i]) ||
	command_line[start + i] == '\0' || !is_cmdand(command_line, (start + i)))
	{
		if (command_line[start + i] == '\0')
			(*e)->current_cmd->error_name = ft_strdup("newline");
		else if (command_line[start + i] == '&')
			(*e)->current_cmd->error_name = ft_strdup("&&");
		else
			(*e)->current_cmd->error_name =
										ft_strndup(command_line, start + i, 1);
		(*e)->current_cmd->error_nbr = -2;
		return (0);
	}
	return (1);
}

static bool	check_error_major(t_env **e, char *command_line, int start)
{
	int i;

	i = 1;
	while (command_line[start + i] == ' ' || command_line[start + i] == '\t' ||
												command_line[start + i] == '\n')
		i++;
	if (!ft_isthischar(";|<({[", command_line[start + i]) ||
	command_line[start + i] == '\0' || !is_cmdand(command_line, (start + i)))
	{
		if (command_line[start + i] == '\0')
			(*e)->current_cmd->error_name = ft_strdup("newline");
		else if (command_line[start + i] == '&')
			(*e)->current_cmd->error_name = ft_strdup("&&");
		else
			(*e)->current_cmd->error_name =
										ft_strndup(command_line, start + i, 1);
		(*e)->current_cmd->error_nbr = -2;
		return (0);
	}
	return (1);
}

char		*check_second_major_double(t_env **e, char *command_line, int start)
{
	if (!check_error_major_double(e, command_line, start))
		return (ft_strdup("\0"));
	(*e)->current_cmd->value_token = VALUE_TOKEN_OUT_REDIRECTION;
	return (ft_strndup(command_line, start, 2));
}

char		*check_second_major(t_env **e, char *command_line, int pos_line,
																int pos_word)
{
	int start;

	start = pos_line + pos_word;
	if (command_line[start + 1] == '>')
		return (check_second_major_double(e, command_line, start));
	if (command_line[start + 1] == '&')
		return (split_agregator_fd(e, command_line, pos_line, pos_word));
	if (!check_error_major(e, command_line, start))
		return (ft_strdup("\0"));
	(*e)->current_cmd->value_token = VALUE_TOKEN_OUT_REDIRECTION;
	return (ft_strdup(">"));
}
