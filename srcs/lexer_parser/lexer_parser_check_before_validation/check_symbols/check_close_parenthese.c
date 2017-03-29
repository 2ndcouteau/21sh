/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close_parenthese.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:06:23 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:47:43 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	remove_parenthese(t_count *tab_count)
{
	if (tab_count->order_position > 0)
	{
		if (tab_count->order_line[tab_count->order_position - 1] == '(')
		{
			tab_count->order_position -= 1;
			tab_count->order_line[tab_count->order_position] = '\0';
			tab_count->parentheses -= 1;
			return (SUCCESS);
		}
	}
	return (ERROR);
}

int			check_close_parenthese(t_count *tab_count)
{
	if (!check_active_condition(tab_count))
	{
		if (tab_count->parentheses == 0)
			return (ERROR_CLOSE_PARENTHESE);
		if (tab_count->parentheses == 1)
		{
			if (remove_parenthese(tab_count))
				return (ERROR_CLOSE_PARENTHESE);
			return (-PARENTHESE);
		}
		else
		{
			if (remove_parenthese(tab_count))
				return (ERROR_CLOSE_PARENTHESE);
		}
	}
	return (0);
}
