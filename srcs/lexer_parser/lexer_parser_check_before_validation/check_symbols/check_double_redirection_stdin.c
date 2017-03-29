/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_redirection_stdin.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 22:15:42 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 17:03:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	check_follow_heredoc(char *str, int i)
{
	i += 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '<')
		return (-2);
	if (str[i] == '>')
		return (-3);
	if (str[i] == '|')
		return (-4);
	if (!is_cmdand(str, i))
		return (-5);
	return (0);
}

void		check_double_redirection_stdin(t_env **e, t_count *tab_count,
													char *command_line, int i)
{
	int	ret;

	i++;
	if (command_line[i] == '<')
	{
		if ((ret = check_follow_heredoc(command_line, i)) < 0)
			tab_count->heredoc_mode = ret;
		else if (tab_count->status <= D_REDICTION_STDIN && (tab_count->pass == 0
								|| tab_count->heredoc_mode == HEREDOC_FINISH))
		{
			if (tab_count->position_last_heredoc_word < i)
			{
				if ((tab_count->status & D_REDICTION_STDIN) !=
															D_REDICTION_STDIN)
					tab_count->status += D_REDICTION_STDIN;
				tab_count->heredoc_mode = HEREDOC_ACTIVE;
				tab_count->heredoc_active = 1;
				tab_count->trim_space = 0;
				(*e)->posicao->heredoc_active = 1;
				add_new_heredoc_word(tab_count, command_line, i + 1);
			}
		}
	}
	else if (i > 1 && command_line[i - 2] != '<')
		tab_count->heredoc_active = 0;
}
