/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_bracket.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:47:40 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:02:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	insert_bracket(t_count *tab_count)
{
	if (tab_count->order_position + 1 <= MAX_OPEN_SIGNS)
	{
		tab_count->brackets += 1;
		tab_count->order_line[tab_count->order_position] = '[';
		tab_count->order_position += 1;
	}
	else
		tab_count->error = ERROR_TOO_MANY_OPEN;
}

int			check_open_bracket(t_count *tab_count)
{
	if (!check_active_condition(tab_count))
	{
		if (tab_count->brackets == 0)
		{
			insert_bracket(tab_count);
			return (BRACKET);
		}
		else
			insert_bracket(tab_count);
	}
	return (0);
}
