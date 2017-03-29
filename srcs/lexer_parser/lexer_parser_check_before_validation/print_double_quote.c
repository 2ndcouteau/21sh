/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:11:18 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:21:00 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool		check_quote_prompt(t_count *tab_count)
{
	if ((tab_count->status & QUOTE) == QUOTE)
	{
		ft_putstr("quote > ");
		tab_count->len_waiting_prompt += 8;
		return (SUCCESS);
	}
	return (ERROR);
}

bool			print_double_quote(t_count *tab_count)
{
	if ((tab_count->status & D_QUOTE) == D_QUOTE)
	{
		if ((tab_count->status & B_QUOTE) == B_QUOTE)
		{
			ft_putstr("dquote bquote ");
			tab_count->len_waiting_prompt += 16;
		}
		else
		{
			ft_putstr("dquote ");
			tab_count->len_waiting_prompt += 9;
		}
		ft_putstr("> ");
		return (SUCCESS);
	}
	else if (!check_quote_prompt(tab_count))
		return (SUCCESS);
	return (ERROR);
}
