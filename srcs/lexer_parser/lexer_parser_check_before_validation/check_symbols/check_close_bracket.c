/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close_bracket.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:53:28 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:46:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	remove_bracket(t_count *tab_count)
{
	if (tab_count->order_position > 0)
	{
		if (tab_count->order_line[tab_count->order_position - 1] == '[')
		{
			tab_count->order_position -= 1;
			tab_count->order_line[tab_count->order_position] = '\0';
			tab_count->brackets -= 1;
			return (SUCCESS);
		}
	}
	return (ERROR);
}

int			check_close_bracket(t_count *tab_count)
{
	if (!check_active_condition(tab_count))
	{
		if (tab_count->brackets == 0)
			return (ERROR_CLOSE_BRACKET);
		if (tab_count->brackets == 1)
		{
			if (remove_bracket(tab_count))
				return (ERROR_CLOSE_BRACKET);
			return (-BRACKET);
		}
		else
		{
			if (remove_bracket(tab_count))
				return (ERROR_CLOSE_BRACKET);
		}
	}
	return (0);
}
