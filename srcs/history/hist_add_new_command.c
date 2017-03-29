/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_add_new_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:33:46 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:28:28 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	init_struct_historical(t_env **e)
{
	if (!((*e)->historical = (t_hist *)malloc(sizeof(t_hist))))
		exit(EXIT_FAILURE);
	(*e)->historical->command_line = ft_strdup((*e)->command_line);
	(*e)->historical->index = 0;
	(*e)->historical->next = NULL;
	(*e)->historical->prev = NULL;
}

void		hist_add_new_command(t_env **e)
{
	if ((*e)->historical == NULL)
		init_struct_historical(e);
	else
	{
		if ((*e)->historical->index < HISTORICAL_LIMIT - 1)
			hist_list_push_front_struct(e);
		else
			hist_list_push_front_max(e);
	}
}
