/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_with_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:48:06 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:16:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static char	exec_without_env(t_env **e)
{
	int		nb_new;
	char	**save_env;
	int		ret;

	ret = SUCCESS;
	save_env = save_env_fct(e);
	(*e)->env = ft_free_tab((*e)->env);
	if (!((*e)->env = (char**)malloc(sizeof(char*))))
		exit(EXIT_FAILURE);
	(*e)->env[0] = NULL;
	nb_new = check_tmp_var(e, 2);
	if (nb_new != 0)
		set_new_var(e, nb_new, 2);
	(*e)->current_cmd->split_line += (2 + nb_new);
	(*e)->current_cmd->size_split_line -= (2 + nb_new);
	(*e)->current_cmd->offset_mark += (2 + nb_new);
	if ((*e)->current_cmd->size_split_line != 0)
		ret = exec_command_for_env(e, (*e)->current_cmd->split_line);
	else if (nb_new != 0)
		print_env(e);
	(*e)->current_cmd->offset_mark -= (2 + nb_new);
	(*e)->current_cmd->size_split_line += (2 + nb_new);
	(*e)->current_cmd->split_line -= (2 + nb_new);
	save_env = restore_env(e, save_env);
	return (ret);
}

char		exec_with_option(t_env **e)
{
	if (!(ft_strncmp((*e)->current_cmd->split_line[1], "-i", 3)))
		return (exec_without_env(e));
	sh_print_error(2, NULL);
	return (ERROR);
}
