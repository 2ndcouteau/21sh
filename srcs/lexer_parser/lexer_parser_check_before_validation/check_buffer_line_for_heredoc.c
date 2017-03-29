/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buffer_line_for_heredoc.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 03:14:53 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 11:41:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	check_buffer_line_for_heredoc(t_env **e, t_count *tab_count,
															char *buffer_line)
{
	if (buffer_line[0] == '\0')
		return ;
	if (tab_count->check_position_heredoc != NULL)
	{
		if (ft_strcmp(tab_count->check_position_heredoc->word, buffer_line))
		{
			tab_count->check_position_heredoc->save_text = lexpar_str_add_join(
					tab_count->check_position_heredoc->save_text, buffer_line);
			return ;
		}
		tab_count->check_position_heredoc =
										tab_count->check_position_heredoc->next;
		if (tab_count->check_position_heredoc == NULL)
		{
			(*e)->posicao->heredoc_active = 0;
			tab_count->heredoc_mode = HEREDOC_FINISH;
			tab_count->heredoc_active = 0;
			tab_count->pass = 0;
			if ((tab_count->status & D_REDICTION_STDIN) == D_REDICTION_STDIN)
				tab_count->status -= D_REDICTION_STDIN;
		}
	}
}
