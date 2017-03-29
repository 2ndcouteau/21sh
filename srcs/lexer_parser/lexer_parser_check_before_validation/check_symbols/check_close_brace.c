/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close_brace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:54:32 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:46:15 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	remove_brace(t_count *tab_count)
{
	if (tab_count->order_position > 0)
	{
		if (tab_count->order_line[tab_count->order_position - 1] == '{')
		{
			tab_count->order_position -= 1;
			tab_count->order_line[tab_count->order_position] = '\0';
			tab_count->braces -= 1;
			return (SUCCESS);
		}
	}
	return (ERROR);
}

int			check_close_brace(t_count *tab_count)
{
	if (!check_active_condition(tab_count))
	{
		if (tab_count->braces == 0)
			return (ERROR_CLOSE_BRACE);
		if (tab_count->braces == 1)
		{
			if (remove_brace(tab_count))
				return (ERROR_CLOSE_BRACE);
			return (-BRACE);
		}
		else
		{
			if (remove_brace(tab_count))
				return (ERROR_CLOSE_BRACE);
		}
	}
	return (0);
}
