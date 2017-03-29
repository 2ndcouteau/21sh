/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:28:36 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 13:48:25 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	check_return_value(t_env **e)
{
	int	ret;

	ret = 0;
	if ((*e)->current_cmd->size_split_line > 1)
	{
		if (!(ft_isnumber((*e)->current_cmd->split_line[1])))
			ret = ft_atoi((*e)->current_cmd->split_line[1]);
		else
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd((*e)->current_cmd->split_line[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			ret = -1;
		}
	}
	return (ret);
}

char		exit_builtin(t_env **e)
{
	int	ret_value;

	ret_value = 0;
	if ((*e)->current_cmd != NULL)
		ret_value = check_return_value(e);
	else
		ft_putchar('\n');
	disable_termcaps();
	free_all_env(e);
	exit(ret_value);
}
