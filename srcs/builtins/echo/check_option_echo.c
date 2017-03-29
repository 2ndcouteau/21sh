/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:13:29 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 18:52:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

short	check_option_echo(t_env **e, short *options)
{
	unsigned int	i;
	bool			mark;

	i = 1;
	mark = 0;
	while (i < (*e)->current_cmd->size_split_line && mark == 0)
	{
		if (!is_valid_option((*e)->current_cmd->split_line[i],
										(*e)->current_cmd->size_split_line))
		{
			set_option((*e)->current_cmd->split_line[i], options);
			i++;
		}
		else
			mark = 1;
	}
	return (i);
}
