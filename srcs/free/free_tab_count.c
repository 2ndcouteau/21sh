/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:54:01 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 13:54:32 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	free_list_heredoc(t_count *tab_count)
{
	t_heredoc *tmp;

	if (tab_count != NULL)
	{
		while (tab_count->begin_list_heredoc != NULL)
		{
			tmp = tab_count->begin_list_heredoc;
			tab_count->begin_list_heredoc = tab_count->begin_list_heredoc->next;
			free(tmp->save_text);
			tmp->save_text = NULL;
			free(tmp->word);
			tmp->word = NULL;
			free(tmp);
			tmp = NULL;
		}
		tab_count->last_word_heredoc = NULL;
		tab_count->check_position_heredoc = NULL;
	}
}

void	free_tab_count(t_env **e)
{
	if ((*e)->tab_count != NULL)
	{
		if ((*e)->tab_count->begin_list_heredoc != NULL)
			free_list_heredoc((*e)->tab_count);
		free((*e)->tab_count);
		(*e)->tab_count = NULL;
	}
}
