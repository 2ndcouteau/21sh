/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:54:18 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:00:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	env_builtin(t_env **e)
{
	if ((*e)->env != NULL)
	{
		if ((*e)->current_cmd->split_line[1] != NULL)
		{
			if ((*e)->current_cmd->split_line[1][0] == '-')
				return (exec_with_option(e));
			else
				return (exec_without_option(e));
		}
		print_env(e);
		return (SUCCESS);
	}
	return (ERROR);
}
