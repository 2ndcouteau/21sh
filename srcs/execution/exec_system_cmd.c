/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_system_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:54:54 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 23:44:42 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	exec_fork(t_env **e, char *path)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) == -1)
		return (error_fork_output());
	if (pid == 0)
	{
		signal(SIGTSTP, SIG_IGN);
		execve(path, (*e)->current_cmd->split_line, (*e)->env);
		path = ft_free_line(&path);
		env_free_all_env(e);
		exit(EXIT_SUCCESS);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		waitpid(pid, &status, 0);
	}
	return (exec_return_status(status));
}

char		exec_system_cmd(t_env **e, char **av)
{
	char	*path;
	char	ret;

	ret = ERROR;
	if (e != NULL && av)
	{
		path = ft_memalloc(PATH_MAX);
		if ((ret = exec_check_path(e, &path)) == 0)
		{
			if ((ret = exec_fork(e, path)) == 0)
			{
				path = ft_free_line(&path);
				return (ret);
			}
		}
		path = ft_free_line(&path);
	}
	return (ret);
}
