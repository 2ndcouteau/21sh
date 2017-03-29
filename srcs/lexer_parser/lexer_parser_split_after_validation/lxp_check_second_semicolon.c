/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_check_second_semicolon.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 19:17:49 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 14:21:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	check_error_semicolon(t_env **e, char *command_line, int start)
{
	int i;

	i = 1;
	while (command_line[start + i] == ' ' || command_line[start + i] == '\t' ||
												command_line[start + i] == '\n')
		i++;
	if (!ft_isthischar(";|", command_line[start + i]) ||
										!is_cmdand(command_line, (start + i)))
	{
		if (command_line[start + i] == ';')
			(*e)->current_cmd->error_name = ft_strdup(";");
		else if (command_line[start + i] == '|')
			(*e)->current_cmd->error_name = ft_strdup("|");
		else
			(*e)->current_cmd->error_name = ft_strdup("&&");
		(*e)->current_cmd->error_nbr = -2;
		return (0);
	}
	return (1);
}

char		*check_second_semicolon(t_env **e, char *command_line, int start)
{
	if (!check_error_semicolon(e, command_line, start))
		return (ft_strdup("\0"));
	(*e)->current_cmd->value_token = VALUE_TOKEN_SEMICOLON;
	return (ft_strdup(";"));
}
