/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_back_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:40:43 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 16:44:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	insert_bquote(t_count *tab_count)
{
	if (tab_count->order_position + 1 <= MAX_OPEN_SIGNS)
	{
		tab_count->order_line[tab_count->order_position] = '`';
		tab_count->order_position += 1;
	}
	else
		tab_count->error = ERROR_TOO_MANY_OPEN;
}

static void	remove_bquote(t_count *tab_count)
{
	if (tab_count->order_position > 0)
	{
		if (tab_count->order_line[tab_count->order_position - 1] == '`')
		{
			tab_count->order_position -= 1;
			tab_count->order_line[tab_count->order_position] = '\0';
		}
	}
}

static int	return_check_back_quote(t_count *tab_count)
{
	if ((tab_count->status & B_QUOTE) == B_QUOTE)
	{
		remove_bquote(tab_count);
		return (-B_QUOTE);
	}
	insert_bquote(tab_count);
	return (B_QUOTE);
}

int			check_back_quote(t_count *tab_count)
{
	if (tab_count->heredoc_active == 0)
	{
		if ((tab_count->status & QUOTE) != QUOTE)
			return (return_check_back_quote(tab_count));
	}
	return (0);
}
