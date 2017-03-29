/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_without_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:47:50 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:50:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	exec_without_option(t_env **e)
{
	int		nb_new;
	char	ret;
	char	**save_env;

	ret = SUCCESS;
	nb_new = check_tmp_var(e, 1);
	if (nb_new != 0)
	{
		save_env = save_env_fct(e);
		set_new_var(e, nb_new, 1);
	}
	(*e)->current_cmd->split_line += (1 + nb_new);
	(*e)->current_cmd->size_split_line -= (1 + nb_new);
	(*e)->current_cmd->offset_mark += (1 + nb_new);
	if ((*e)->current_cmd->size_split_line != 0)
		ret = exec_command_for_env(e, (*e)->current_cmd->split_line);
	else
		print_env(e);
	(*e)->current_cmd->offset_mark -= (1 + nb_new);
	(*e)->current_cmd->size_split_line += (1 + nb_new);
	(*e)->current_cmd->split_line -= (1 + nb_new);
	if (nb_new != 0)
		save_env = restore_env(e, save_env);
	return (ret);
}
