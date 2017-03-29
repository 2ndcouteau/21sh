/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_check_second_andco.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:06:49 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:42:57 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static char	*check_third_andco(t_env **e, char *command_line, int start)
{
	int a;

	a = 2;
	while (command_line[start + a] == ' ' || command_line[start + a] == '\t' ||
												command_line[start + a] == '\n')
		a++;
	if (command_line[start + a] == ';' || command_line[start + a] == '|' ||
										!is_cmdand(command_line, (start + a)))
	{
		if (command_line[start + a] == ';')
			(*e)->current_cmd->error_name = ft_strdup(";");
		else if (command_line[start + a] == '|')
			(*e)->current_cmd->error_name = ft_strdup("|");
		else if (command_line[start + a] == '&')
			(*e)->current_cmd->error_name = ft_strdup("&&");
		(*e)->current_cmd->error_nbr = -2;
		return (ft_strdup("\0"));
	}
	(*e)->current_cmd->value_token = VALUE_TOKEN_AND;
	return (ft_strdup("&&"));
}

char		*check_second_andco(t_env **e, char *command_line, int start)
{
	return (check_third_andco(e, command_line, start));
}
