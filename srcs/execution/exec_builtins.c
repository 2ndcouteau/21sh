/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:20:25 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/08 02:31:29 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char						(*g_builtins[NB_BUILTIN])(t_env **e) =
{
	cd_builtin,
	env_builtin,
	setenv_builtin,
	unsetenv_builtin,
	exit_builtin,
	envreset_builtin,
	history_builtin,
	echo_builtin
};

static const char *const	g_builtins_name[NB_BUILTIN] = {
	"cd",
	"env",
	"setenv",
	"unsetenv",
	"exit",
	"envreset",
	"history",
	"echo"
};

static int					is_builtins(char *cmd_search, char const *full_name)
{
	if (cmd_search[0] == full_name[0])
		return (ft_strcmp(full_name, cmd_search));
	return (ERROR);
}

char						exec_builtins(t_env **e)
{
	int		cpt;

	cpt = 0;
	while (cpt < NB_BUILTIN)
	{
		if (is_builtins((*e)->current_cmd->split_line[0],\
	g_builtins_name[cpt]) == 0)
		{
			return (g_builtins[cpt](e));
		}
		cpt++;
	}
	return (-1);
}
