/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_brace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:45:54 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:58:53 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	insert_brace(t_count *tab_count)
{
	if (tab_count->order_position + 1 <= MAX_OPEN_SIGNS)
	{
		tab_count->braces += 1;
		tab_count->order_line[tab_count->order_position] = '{';
		tab_count->order_position += 1;
	}
	else
		tab_count->error = ERROR_TOO_MANY_OPEN;
}

int			check_open_brace(t_count *tab_count)
{
	if (!check_active_condition(tab_count))
	{
		if (tab_count->braces == 0)
		{
			insert_brace(tab_count);
			return (BRACE);
		}
		else
			insert_brace(tab_count);
	}
	return (0);
}
