/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:47:44 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:17:44 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static char	**cd_init_define(void)
{
	char	**mytab;

	if (!(mytab = (char**)malloc(sizeof(char*) * 7)))
		return (NULL);
	mytab[0] = ft_strdup("cd");
	mytab[1] = ft_strdup("-LP");
	mytab[2] = ft_strdup("");
	mytab[3] = ft_strdup(" [-L|-P]");
	mytab[4] = ft_strdup("");
	mytab[5] = ft_strdup("[dir]");
	mytab[6] = NULL;
	return (mytab);
}

void		exec_cd(t_env **e, t_opt **cd_opt)
{
	char	*current_pwd;

	current_pwd = ft_memalloc(PATH_MAX);
	getcwd(current_pwd, PATH_MAX);
	cd_create_path_name(e, cd_opt, &current_pwd);
	if ((*e)->current_cmd->error_nbr != 0)
	{
		cd_print_error((*e)->current_cmd->error_nbr,
	(*e)->current_cmd->error_name);
	}
	else
	{
		chdir(current_pwd);
		cd_swap_pwd_env(e, &current_pwd, cd_opt);
	}
	current_pwd = ft_free_line(&current_pwd);
}

char		cd_builtin(t_env **e)
{
	char	**cd_init;
	t_opt	*cd_opt;

	cd_init = cd_init_define();
	cd_opt = opt_parse_arguments((*e)->current_cmd->size_split_line,\
	(*e)->current_cmd->split_line, cd_init);
	if (cd_opt->mark != 2)
	{
		exec_cd(e, &cd_opt);
		opt_free(&cd_opt);
		if ((*e)->current_cmd->error_nbr != 0)
			return (ERROR);
		return (SUCCESS);
	}
	opt_print_error((*e)->current_cmd->split_line, &cd_opt);
	opt_free(&cd_opt);
	return (ERROR);
}
