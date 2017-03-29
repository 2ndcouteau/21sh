/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_check_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:48:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:14:52 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	check_exec_command(char *path)
{
	struct stat	t_stat;
	char		check;

	if (lstat(path, &t_stat) >= 0)
	{
		check = ft_check_typefile(t_stat.st_mode & S_IFMT);
		if (check == '-' || check == 'l')
		{
			if (access(path, X_OK) == 0)
				return (0);
			return (3);
		}
		return (2);
	}
	return (1);
}

static bool	current_path_exec(t_env **e, char **path)
{
	char		pre_path[PATH_MAX];
	int			error;

	ft_bzero(pre_path, PATH_MAX);
	getcwd(pre_path, PATH_MAX);
	*path = ft_strjoin(pre_path, (*e)->current_cmd->split_line[0] + 1);
	if ((error = check_exec_command(*path)) == 0)
		return (SUCCESS);
	exec_print_error(error, (*e)->current_cmd->split_line[0]);
	return (ERROR);
}

static bool	env_path_exec(t_env **e, char **path, int path_pos, int error)
{
	char		**line;
	int			cpt;

	cpt = 0;
	line = ft_strsplit((*e)->env[path_pos] + 5, ':');
	while (line[cpt] != NULL && error != 2)
	{
		*path = ft_strncpy(*path, line[cpt], ft_strlen(line[cpt]));
		if (!sh_add_end_path(path, (*e)->current_cmd->split_line[0],
	ft_strlen(*path)))
		{
			if ((error = check_exec_command(*path)) == 0)
			{
				line = ft_free_tab(line);
				return (SUCCESS);
			}
		}
		error = 1;
		ft_bzero(*path, PATH_MAX);
		cpt++;
	}
	line = ft_free_tab(line);
	exec_print_error(error, (*e)->current_cmd->split_line[0]);
	return (ERROR);
}

static bool	absolute_path_exec(t_env **e, char **path)
{
	int			error;

	*path = ft_strncpy(*path, (*e)->current_cmd->split_line[0],
	ft_strlen((*e)->current_cmd->split_line[0]));
	if ((error = check_exec_command(*path)) == 0)
		return (SUCCESS);
	exec_print_error(error, (*e)->current_cmd->split_line[0]);
	return (ERROR);
}

bool		exec_check_path(t_env **e, char **path)
{
	int			path_pos;

	if (!(ft_strncmp((*e)->current_cmd->split_line[0], "./", 2)))
	{
		if (!(current_path_exec(e, path)))
			return (SUCCESS);
	}
	else if ((*e)->current_cmd->split_line[0][0] == '/')
	{
		if (!(absolute_path_exec(e, path)))
			return (SUCCESS);
	}
	else if ((path_pos = env_position_line(e, "PATH=", 5)) != -1)
	{
		if (!(env_path_exec(e, path, path_pos, 0)))
			return (SUCCESS);
	}
	else
		exec_print_error(1, (*e)->current_cmd->split_line[0]);
	return (ERROR);
}
