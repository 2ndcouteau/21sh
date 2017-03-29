/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexpar_init_tab_count_new_command.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 11:00:48 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 11:46:03 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	init_tab_count_new_command(t_count *tab_count)
{
	tab_count->status = 0;
	ft_bzero(tab_count->order_line, (MAX_LEN_COMMAND / 2));
	tab_count->order_position = 0;
	tab_count->heredoc_active = 0;
	tab_count->back_slash = 0;
	tab_count->diese = 0;
	tab_count->parentheses = 0;
	tab_count->braces = 0;
	tab_count->brackets = 0;
	tab_count->error = 0;
	tab_count->len_waiting_prompt = 0;
	tab_count->pass = 0;
	tab_count->heredoc_mode = NO_HEREDOC;
	tab_count->position_last_heredoc_word = 0;
	tab_count->begin_list_heredoc = NULL;
	tab_count->check_position_heredoc = NULL;
	tab_count->last_word_heredoc = NULL;
}
