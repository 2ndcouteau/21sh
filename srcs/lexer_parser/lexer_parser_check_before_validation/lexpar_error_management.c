/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexpar_error_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:13:53 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:38:54 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	error_isnot_close_symbols(int status)
{
	if ((status & ERROR_NOT_CLOSE_BRACKET) != ERROR_NOT_CLOSE_BRACKET)
	{
		if ((status & ERROR_NOT_CLOSE_BRACE) != ERROR_NOT_CLOSE_BRACE)
		{
			if ((status & ERROR_NOT_CLOSE_PARENTHESE) !=
													ERROR_NOT_CLOSE_PARENTHESE)
				return (ERROR);
			else
				ft_putstr_fd("\n21sh: a Parenthese group is not close.", 2);
		}
		else
			ft_putstr_fd("\n21sh: a Brace group is not close.", 2);
	}
	else
		ft_putstr_fd("\n21sh: a Backet group is not close.", 2);
	return (SUCCESS);
}

static bool	error_status_symbols(int status)
{
	if ((status & ERROR_CLOSE_PARENTHESE) != ERROR_CLOSE_PARENTHESE)
	{
		if ((status & ERROR_CLOSE_BRACE) != ERROR_CLOSE_BRACE)
		{
			if ((status & ERROR_CLOSE_BRACKET) != ERROR_CLOSE_BRACKET)
				return (ERROR);
			else
				ft_putstr_fd(
						"\n21sh: syntax error near unexpected token ']'", 2);
		}
		else
			ft_putstr_fd("\n21sh: syntax error near unexpected token '}'", 2);
	}
	else
		ft_putstr_fd("\n21sh: syntax error near unexpected token ')'", 2);
	return (SUCCESS);
}

bool		error_heredoc_mode(t_env **e)
{
	if ((*e)->tab_count->heredoc_mode < 0)
	{
		if ((*e)->tab_count->heredoc_mode == -1)
			ft_putstr_fd(
		"\n21sh: syntax error near unexpected empty token after \"<<\".", 2);
		else if ((*e)->tab_count->heredoc_mode == -2)
			ft_putstr_fd("\n21sh: syntax error near unexpected token '<'", 2);
		else if ((*e)->tab_count->heredoc_mode == -3)
			ft_putstr_fd("\n21sh: syntax error near unexpected token '>'", 2);
		else if ((*e)->tab_count->heredoc_mode == -4)
			ft_putstr_fd("\n21sh: syntax error near unexpected token '|'", 2);
		(*e)->tab_count->heredoc_mode = NO_HEREDOC;
		return (SUCCESS);
	}
	return (ERROR);
}

bool		error_status(t_env **e)
{
	if ((*e)->tab_count->error != ERROR_TOO_MANY_OPEN)
	{
		if (!error_isnot_close_symbols((*e)->tab_count->status))
			return (SUCCESS);
		else if (!error_status_symbols((*e)->tab_count->status))
			return (SUCCESS);
		else if (!error_heredoc_mode(e))
			return (SUCCESS);
		else if (((*e)->posicao->len_full_command +
					(*e)->tab_count->order_position) < MAX_LEN_COMMAND - 1 ||
										(*e)->tab_count->order_line[0] == '\0')
			return (ERROR);
		else
			ft_putstr_fd(
"\n21sh: syntax error, not enough available characteres for close open signs.",
																			2);
	}
	else
	{
		ft_putstr_fd("\n21sh: syntax error, too many open signs. Max: ", 2);
		ft_putnbr_fd(MAX_OPEN_SIGNS, 2);
	}
	return (SUCCESS);
}

bool		error_check(int status, int heredoc_mode)
{
	if (heredoc_mode >= NO_HEREDOC)
	{
		if ((status & ERROR_CLOSE_PARENTHESE) != ERROR_CLOSE_PARENTHESE)
		{
			if ((status & ERROR_CLOSE_BRACE) != ERROR_CLOSE_BRACE)
			{
				if ((status & ERROR_CLOSE_BRACKET) != ERROR_CLOSE_BRACKET)
					return (SUCCESS);
			}
		}
	}
	return (ERROR);
}
