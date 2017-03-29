/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_active_condition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 02:59:19 by cristal           #+#    #+#             */
/*   Updated: 2016/07/21 19:14:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	check_active_condition(t_count *tab_count)
{
	if (tab_count->heredoc_active == 0)
	{
		if ((tab_count->status & QUOTE) != QUOTE)
		{
			if ((tab_count->status & B_QUOTE) != B_QUOTE)
			{
				if ((tab_count->status & D_QUOTE) != D_QUOTE)
					return (SUCCESS);
			}
		}
	}
	return (ERROR);
}
