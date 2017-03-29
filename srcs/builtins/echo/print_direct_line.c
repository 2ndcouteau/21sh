/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_direct_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:16:34 by qrosa             #+#    #+#             */
/*   Updated: 2016/09/09 16:21:10 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	print_direct_line(t_env **e, unsigned int tab_position, short options)
{
	while (tab_position < (*e)->current_cmd->size_split_line)
	{
		ft_putstr((*e)->current_cmd->split_line[tab_position]);
		if (tab_position + 1 < (*e)->current_cmd->size_split_line)
			ft_putchar(' ');
		tab_position += 1;
	}
	if ((options & 2) != 2)
		ft_putchar('\n');
}
