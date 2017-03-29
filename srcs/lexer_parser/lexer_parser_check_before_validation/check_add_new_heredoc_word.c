/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_add_new_heredoc_word.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 03:29:17 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 16:43:43 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	init_list_heredoc(t_count *tab_count, char *command_line, int i)
{
	if (!(tab_count->begin_list_heredoc =
										(t_heredoc*)malloc(sizeof(t_heredoc))))
		exit(ERROR);
	tab_count->check_position_heredoc = tab_count->begin_list_heredoc;
	tab_count->last_word_heredoc = tab_count->begin_list_heredoc;
	tab_count->last_word_heredoc->word = NULL;
	tab_count->check_position_heredoc->save_text = NULL;
	tab_count->check_position_heredoc->next = NULL;
	dup_heredoc_word(tab_count, command_line, i);
}

static void	add_new_word_heredoc_list(t_count *tab_count, char *command_line,
																		int i)
{
	if (!(tab_count->last_word_heredoc->next =
										(t_heredoc*)malloc(sizeof(t_heredoc))))
		exit(ERROR);
	tab_count->last_word_heredoc = tab_count->last_word_heredoc->next;
	tab_count->last_word_heredoc->next = NULL;
	tab_count->last_word_heredoc->save_text = NULL;
	tab_count->last_word_heredoc->word = NULL;
	if (tab_count->check_position_heredoc == NULL)
		tab_count->check_position_heredoc = tab_count->last_word_heredoc;
	dup_heredoc_word(tab_count, command_line, i);
}

void		add_new_heredoc_word(t_count *tab_count, char *command_line, int i)
{
	if (tab_count->begin_list_heredoc == NULL)
		init_list_heredoc(tab_count, command_line, i);
	else
		add_new_word_heredoc_list(tab_count, command_line, i);
}
