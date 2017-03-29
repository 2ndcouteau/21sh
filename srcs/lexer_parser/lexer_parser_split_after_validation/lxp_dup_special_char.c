/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_dup_special_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 19:57:07 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 11:30:47 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static const char
g_special_dup_split_special_char[NB_SPECIAL_DUP_SPLIT_SPECIAL_CHAR] = {
	')',
	'}',
	']',
	'(',
	'{',
	'[',
	';',
	'|',
	'<',
	'>',
	'&'
};

static char			*check_second_symbol(t_env **e, char *command_line,
													int pos_line, int pos_word)
{
	int	start;

	start = pos_line + pos_word;
	if (command_line[start] == ';')
		return (check_second_semicolon(e, command_line, start));
	else if (command_line[start] == '|')
		return (check_second_pipe(e, command_line, start));
	else if (command_line[start] == '<')
		return (check_second_minor(e, command_line, start));
	else if (command_line[start] == '>')
		return (check_second_major(e, command_line, pos_line, pos_word));
	else
		return (check_second_andco(e, command_line, start));
}

char				*lxp_dup_special_char(t_env **e, char *command_line,
													int pos_line, int pos_word)
{
	int	start;
	int	pos_symbol;

	pos_symbol = 0;
	start = pos_line + pos_word;
	if (ft_isdigit(command_line[pos_line + pos_word]))
		return (split_agregator_fd(e, command_line, pos_line, pos_word));
	while (pos_symbol < NB_SPECIAL_DUP_SPLIT_SPECIAL_CHAR)
	{
		if (command_line[start] == g_special_dup_split_special_char[pos_symbol])
		{
			if (pos_symbol > 5)
				return (check_second_symbol(e, command_line, pos_line,
																	pos_word));
			else
			{
				(*e)->current_cmd->value_token = VALUE_TOKEN_COMMAND;
				return (ft_strndup(command_line, start, 1));
			}
		}
		pos_symbol++;
	}
	return (ft_strdup("\0"));
}
