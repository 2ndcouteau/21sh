/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diese.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:50:30 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 17:03:02 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	check_empty_start_line(char *command_line)
{
	int i;

	i = 0;
	while (command_line[i] != '\0' && (command_line[i] == ' ' || command_line[i]
											== '\t' || command_line[i] == '\n'))
		i++;
	if (command_line[i] == '#')
		return (SUCCESS);
	return (ERROR);
}

static bool	check_status_value_for_diese(t_count *tab_count)
{
	if (tab_count->status >= DIESE)
	{
		if ((tab_count->status & QUOTE) != QUOTE &&
								(tab_count->status & D_QUOTE) != D_QUOTE &&
									(tab_count->status & B_QUOTE) != B_QUOTE)
		{
			if (tab_count->order_position > 0)
			{
				if (tab_count->order_line[tab_count->order_position - 1] ==
																			'(')
					tab_count->status += ERROR_NOT_CLOSE_PARENTHESE;
				else if (tab_count->order_line[tab_count->order_position - 1] ==
																			'{')
					tab_count->status += ERROR_NOT_CLOSE_BRACE;
				else if (tab_count->order_line[tab_count->order_position - 1] ==
																			'[')
					tab_count->status += ERROR_NOT_CLOSE_BRACKET;
			}
			return (0);
		}
		return (1);
	}
	return (0);
}

void		check_diese(t_count *tab_count, char *command_line, int i)
{
	if (i == 0 || command_line[i - 1] == ' ' || command_line[i - 1] == '\t' ||
													command_line[i - 1] == '\n')
	{
		if (!check_status_value_for_diese(tab_count))
		{
			tab_count->status += DIESE;
			if (i == 0 || !check_empty_start_line(command_line))
				tab_count->diese = 1;
		}
	}
}
