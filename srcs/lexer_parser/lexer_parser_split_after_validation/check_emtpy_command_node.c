/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_emtpy_command_node.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:56:54 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:40:36 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	check_empty_command_node(char *command_line, int pos_line, int pos_word)
{
	int i;

	i = 0;
	while (i < pos_word)
	{
		if (command_line[pos_line + i] != ' ' && command_line[pos_line + i] !=
									'\t' && command_line[pos_line + i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
