/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:05:58 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/10 22:38:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static char	out_redirection(t_env **e, t_cut_line *list, char **av, char mode)
{
	int		save_fd;

	save_fd = dup(STDOUT_FILENO);
	if (browse_search_last_fd(list->right, mode) == -1)
	{
		dup2(save_fd, STDOUT_FILENO);
		return (ERROR);
	}
	exec_ast(e, list->left, av);
	dup2(save_fd, STDOUT_FILENO);
	if (close(save_fd) == -1)
		return (ERROR);
	return (SUCCESS);
}

static void	error_open_in(char *pathname)
{
	if (errno == EACCES || errno == EISDIR)
	{
		ft_putstr_fd("21sh: Permission denied: ", 2);
		ft_putendl_fd(pathname, 2);
	}
	else if (errno == ENOENT)
	{
		ft_putstr_fd("21sh: No such file or directory: ", 2);
		ft_putendl_fd(pathname, 2);
	}
	else
		ft_putendl_fd("21sh: Error file-descriptor in_redirection", 2);
}

static char	simple_in_redirection(t_env **e, t_cut_line *list, char **av,
														t_cut_line *browse_tmp)
{
	int			fd;
	int			save_fd;

	save_fd = dup(STDIN_FILENO);
	if ((fd = open(browse_tmp->command_part, O_RDONLY)) != -1)
	{
		dup2(fd, STDIN_FILENO);
		exec_ast(e, list->left, av);
		dup2(save_fd, STDIN_FILENO);
		close(fd);
		if (close(save_fd) == -1)
			return (ERROR);
		return (SUCCESS);
	}
	error_open_in(browse_tmp->command_part);
	dup2(save_fd, STDIN_FILENO);
	close(save_fd);
	return (ERROR);
}

char		in_redirection(t_env **e, t_cut_line *list, char **av)
{
	t_cut_line	*browse_tmp;

	browse_tmp = list;
	while (browse_tmp->right->right != NULL)
	{
		if (browse_tmp->special_char[1] == '<')
			free_node_heredoc(e);
		browse_tmp = browse_tmp->right;
	}
	if (browse_tmp->special_char[1] == '<')
	{
		if (exec_heredoc(e, list, av))
			return (ERROR);
	}
	else
	{
		if (simple_in_redirection(e, list, av, browse_tmp->right))
			return (ERROR);
	}
	return (SUCCESS);
}

char		exec_redirection(t_env **e, t_cut_line *list, char **av)
{
	if (list->value_token == VALUE_TOKEN_OUT_REDIRECTION)
	{
		if (list->special_char[1] == '>')
			return (out_redirection(e, list, av, DOUBLE_OUT_REDICTION));
		else
			return (out_redirection(e, list, av, SIMPLE_OUT_REDICTION));
	}
	else
		return (in_redirection(e, list, av));
}
