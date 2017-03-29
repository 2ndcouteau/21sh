/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_offset_redirection_mode.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:24:58 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:42:15 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static char	check_heredoc_mode(t_env **e)
{
	if ((*e)->current_cmd->last_node_list->value_token ==
													VALUE_TOKEN_IN_REDIRECTION)
	{
		if ((*e)->current_cmd->last_node_list->special_char[1] == '<')
			return (1);
	}
	return (0);
}

int			count_offset_redirection_name(t_env **e, char *command_line,
													int pos_line, int pos_word)
{
	int		i;
	char	sign;
	char	heredoc_mode;

	i = 0;
	sign = 0;
	heredoc_mode = check_heredoc_mode(e);
	while (i < pos_word && !ft_isthischar(" \n\t", command_line[pos_line + i]))
		++i;
	while ((i < pos_word && ft_isthischar(" \n\t", command_line[pos_line + i]))
												|| (i < pos_word && sign != 0))
	{
		if (!ft_isthischar("\"\'", command_line[pos_line + i]) &&
													heredoc_mode == NO_HEREDOC)
		{
			if (sign == 0)
				sign = command_line[pos_line + i];
			else if (command_line[pos_line + i] == sign)
				sign = 0;
		}
		else if (command_line[pos_line + i] == '\\')
			++i;
		++i;
	}
	return (i);
}
