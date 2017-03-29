/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parenthese_brace_bracket.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:10:05 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:21:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void		add_dquote_bquote(t_count *tab_count)
{
	if ((tab_count->status & D_QUOTE) == D_QUOTE)
	{
		if ((tab_count->status & B_QUOTE) == B_QUOTE)
		{
			ft_putstr("dquote bquote ");
			tab_count->len_waiting_prompt += 14;
		}
		else
		{
			ft_putstr("dquote ");
			tab_count->len_waiting_prompt += 7;
		}
	}
	else if ((tab_count->status & B_QUOTE) == B_QUOTE)
	{
		ft_putstr("bquote ");
		tab_count->len_waiting_prompt += 7;
	}
	else if ((tab_count->status & QUOTE) == QUOTE)
	{
		ft_putstr("quote ");
		tab_count->len_waiting_prompt += 6;
	}
}

static void		add_count_len_waiting_prompt(t_count *tab_count, char symbol)
{
	if (symbol == '(')
		tab_count->len_waiting_prompt += 12;
	else if (symbol == '{')
		tab_count->len_waiting_prompt += 7;
	else if (symbol == '[')
		tab_count->len_waiting_prompt += 9;
}

bool			print_parenthese_brace_bracket(t_count *tab_count)
{
	int cpt;

	cpt = 0;
	if (tab_count->order_position != 0)
	{
		while (cpt < tab_count->order_position)
		{
			if (tab_count->order_line[cpt] == '(')
				ft_putstr("parentheses ");
			else if (tab_count->order_line[cpt] == '{')
				ft_putstr("braces ");
			else if (tab_count->order_line[cpt] == '[')
				ft_putstr("brackets ");
			add_count_len_waiting_prompt(tab_count, tab_count->order_line[cpt]);
			cpt++;
		}
		add_dquote_bquote(tab_count);
		tab_count->len_waiting_prompt += 2;
		ft_putstr("> ");
		return (SUCCESS);
	}
	return (ERROR);
}
