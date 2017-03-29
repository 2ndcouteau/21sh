/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_semi_colon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:40:15 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:33:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	reset_tab_count(t_count *tab_count)
{
	tab_count->heredoc_active = 0;
	if (tab_count->order_line[0] == '(')
		tab_count->status += ERROR_NOT_CLOSE_PARENTHESE;
	else if (tab_count->order_line[0] == '[')
		tab_count->status += ERROR_NOT_CLOSE_BRACKET;
	else if (tab_count->order_line[0] == '{')
		tab_count->status += ERROR_NOT_CLOSE_BRACE;
}

int			check_semi_colon(t_count *tab_count)
{
	if ((tab_count->status & QUOTE) != QUOTE)
	{
		if ((tab_count->status & B_QUOTE) != B_QUOTE)
		{
			if ((tab_count->status & D_QUOTE) != D_QUOTE)
				reset_tab_count(tab_count);
		}
	}
	return (0);
}
