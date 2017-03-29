/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 22:46:33 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:57:45 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	insert_dquote(t_count *tab_count)
{
	if (tab_count->order_position + 1 <= MAX_OPEN_SIGNS)
	{
		tab_count->order_line[tab_count->order_position] = '\"';
		tab_count->order_position += 1;
	}
	else
		tab_count->error = ERROR_TOO_MANY_OPEN;
}

static void	remove_dquote(t_count *tab_count)
{
	if (tab_count->order_position > 0)
	{
		if (tab_count->order_line[tab_count->order_position - 1] == '\"')
		{
			tab_count->order_position -= 1;
			tab_count->order_line[tab_count->order_position] = '\0';
		}
	}
}

static int	return_check_double_quote(t_count *tab_count)
{
	if ((tab_count->status & D_QUOTE) == D_QUOTE)
	{
		remove_dquote(tab_count);
		return (-D_QUOTE);
	}
	insert_dquote(tab_count);
	return (D_QUOTE);
}

int			check_double_quote(t_count *tab_count)
{
	if (tab_count->heredoc_active == 0)
	{
		if ((tab_count->status & QUOTE) != QUOTE)
		{
			if ((tab_count->status & B_QUOTE) != B_QUOTE)
				return (return_check_double_quote(tab_count));
		}
	}
	return (0);
}
