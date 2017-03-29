/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_is_special_split_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:40:23 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:55:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static const char	g_special_split_char[NB_SPECIAL_SPLIT_CHAR] = {
	'`',
	'\'',
	'\"',
	')',
	'}',
	']',
	'(',
	'{',
	'[',
	';',
	'<',
	'>',
	'|',
	'#',
	'&'
};

static bool			check_is_heredoc_enable(char *command_line, int start,
													t_cmd *current_cmd, int i)
{
	if (i < 6)
		current_cmd->nb_order_line -= 1;
	else if (i < 9)
		current_cmd->nb_order_line += 1;
	else if (i == 10)
	{
		if (command_line[start + 1] == '<' || (start > 0 &&
												command_line[start - 1] == '<'))
		{
			if (current_cmd->nb_order_line != 0)
				return (1);
		}
	}
	return (0);
}

static bool			check_is_commentary_active(char *command_line, int start)
{
	if (command_line[start] == '#')
	{
		if (start > 0)
		{
			if (command_line[start - 1] != ' ' && command_line[start - 1] !=
										'\t' && command_line[start - 1] != '\n')
				return (1);
			else
			{
				if (start > 0 && check_back_slash(command_line, start - 1))
					return (1);
			}
		}
	}
	return (0);
}

static bool			return_special_split_char(char *command_line, int start,
													t_cmd *current_cmd, int i)
{
	if (i > 2)
	{
		if (current_cmd->double_char[0] == '\0' &&
										!check_back_slash(command_line, start))
		{
			if (!check_is_heredoc_enable(command_line, start, current_cmd, i) &&
							!check_is_commentary_active(command_line, start))
			{
				if (command_line[start] != '&' ||
												!is_cmdand(command_line, start))
					return (0);
			}
		}
	}
	else
		add_suppr_double_char(current_cmd->double_char, command_line, start);
	return (1);
}

bool				is_special_split_char(char *command_line, int start,
										t_cmd *current_cmd, int *heredoc_mode)
{
	int	i;

	i = 0;
	if (command_line[start] == '\0')
		return (0);
	if (*heredoc_mode == HEREDOC_ACTIVE)
	{
		if (!ft_isthischar(";|><", command_line[start]) ||
												!is_cmdand(command_line, start))
			return (0);
		return (1);
	}
	while (i < NB_SPECIAL_SPLIT_CHAR)
	{
		if (command_line[start] == g_special_split_char[i])
		{
			if (!return_special_split_char(command_line, start, current_cmd, i))
				return (0);
			return (1);
		}
		i++;
	}
	return (1);
}
