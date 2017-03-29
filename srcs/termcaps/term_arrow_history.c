/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_arrow_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:30:04 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:14:53 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool		history_print_new_line(t_env **e, char **new_tmp)
{
	ctrl_a(e, new_tmp);
	if (put_stdout("cd"))
		return (ERROR);
	sh_special_putstr(*new_tmp);
	(*e)->posicao->len_command = ft_strlen(*new_tmp);
	(*e)->posicao->len_full_command = (*e)->posicao->len_command;
	(*e)->posicao->absolute_pos = (*e)->posicao->len_command +
													(*e)->posicao->len_prompt;
	term_set_cursor_position((*e)->posicao);
	replace_cursor((*e)->posicao);
	return (SUCCESS);
}

static void		arrow_up_start(t_env **e, char **new_tmp)
{
	(*e)->posicao->current_history = (*e)->posicao->copy_hist_begin;
	ft_bzero((*e)->posicao->ptr_new_tmp, MAX_LEN_COMMAND);
	ft_strcpy((*e)->posicao->ptr_new_tmp, *new_tmp);
	ft_bzero(*new_tmp, MAX_LEN_COMMAND);
	ft_strcpy(*new_tmp, (*e)->posicao->current_history->line);
}

static void		arrow_up_until_end(t_env **e, char **new_tmp)
{
	ft_bzero((*e)->posicao->current_history->line, MAX_LEN_COMMAND);
	ft_strcpy((*e)->posicao->current_history->line, *new_tmp);
	(*e)->posicao->current_history = (*e)->posicao->current_history->next;
	ft_bzero(*new_tmp, MAX_LEN_COMMAND);
	ft_strcpy(*new_tmp, (*e)->posicao->current_history->line);
}

bool			arrow_up(t_env **e, char **new_tmp)
{
	if ((*e)->posicao->copy_hist_begin != NULL &&
											(*e)->posicao->waiting_mode == 0)
	{
		if ((*e)->posicao->current_history == NULL)
			arrow_up_start(e, new_tmp);
		else if ((*e)->posicao->current_history->next != NULL)
			arrow_up_until_end(e, new_tmp);
		else
			return (ERROR);
		history_print_new_line(e, new_tmp);
		return (SUCCESS);
	}
	else
		return (ERROR);
}

bool			arrow_down(t_env **e, char **new_tmp)
{
	t_position *posicao;

	posicao = (*e)->posicao;
	if (posicao->current_history != NULL && (*e)->posicao->waiting_mode == 0)
	{
		if (posicao->current_history->prev == NULL)
		{
			ft_bzero((*e)->posicao->current_history->line, MAX_LEN_COMMAND);
			ft_strcpy((*e)->posicao->current_history->line, *new_tmp);
			posicao->current_history = NULL;
			ft_bzero(*new_tmp, MAX_LEN_COMMAND);
			ft_strcpy(*new_tmp, posicao->ptr_new_tmp);
		}
		else
		{
			ft_bzero((*e)->posicao->current_history->line, MAX_LEN_COMMAND);
			ft_strcpy((*e)->posicao->current_history->line, *new_tmp);
			posicao->current_history = posicao->current_history->prev;
			ft_bzero(*new_tmp, MAX_LEN_COMMAND);
			ft_strcpy(*new_tmp, posicao->current_history->line);
		}
		history_print_new_line(e, new_tmp);
		return (SUCCESS);
	}
	return (ERROR);
}
