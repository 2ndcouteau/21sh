/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexpar_print_waiting_prompt.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 01:13:56 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 17:16:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		print_waiting_prompt(t_count *tab_count, bool jump)
{
	if (jump == 1)
		ft_putstr("\n");
	tab_count->len_waiting_prompt = 0;
	if (!print_heredocs(tab_count))
		return ;
	if (!print_parenthese_brace_bracket(tab_count))
		return ;
	else if (!print_double_quote(tab_count))
		return ;
	else if ((tab_count->status & B_QUOTE) == B_QUOTE)
	{
		ft_putstr("bquote ");
		tab_count->len_waiting_prompt += 9;
	}
	else if ((tab_count->status & QUOTE) == QUOTE)
	{
		ft_putstr("quote ");
		tab_count->len_waiting_prompt += 8;
	}
	ft_putstr("> ");
}
