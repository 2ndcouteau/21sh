/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:10:04 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:10:47 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

/*
**	This function browse the binary_tree_execution and execute each part of the
**	command_line.
*/

char	exec_command(t_env **e, t_cut_line *list, char **av)
{
	char	ret;

	ret = 0;
	(*e)->current_cmd->split_line = split_clean_command(e, list->command_part);
	(*e)->current_cmd->size_split_line =
									ft_tablen((*e)->current_cmd->split_line);
	if ((*e)->current_cmd->split_line[0] != NULL)
	{
		if (((ret = exec_builtins(e)) & 2) == 2)
			ret = exec_system_cmd(e, av);
	}
	(*e)->current_cmd->split_line = ft_free_tab((*e)->current_cmd->split_line);
	(*e)->current_cmd->size_split_line = 0;
	return (ret);
}
