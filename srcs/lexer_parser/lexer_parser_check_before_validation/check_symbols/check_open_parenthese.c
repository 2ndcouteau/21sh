/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_parenthese.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:35:16 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:01:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	insert_parenthese(t_count *tab_count)
{
	if (tab_count->order_position + 1 <= MAX_OPEN_SIGNS)
	{
		tab_count->parentheses += 1;
		tab_count->order_line[tab_count->order_position] = '(';
		tab_count->order_position += 1;
	}
	else
		tab_count->error = ERROR_TOO_MANY_OPEN;
}

int			check_open_parenthese(t_count *tab_count)
{
	if (!check_active_condition(tab_count))
	{
		if (tab_count->parentheses == 0)
		{
			insert_parenthese(tab_count);
			return (PARENTHESE);
		}
		else
			insert_parenthese(tab_count);
	}
	return (0);
}
