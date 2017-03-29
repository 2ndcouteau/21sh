/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_search_last_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:03:37 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/10 22:38:50 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	error_open_out(char *pathname)
{
	if (errno == EACCES)
	{
		ft_putstr_fd("21sh: Permission denied: ", 2);
		ft_putendl_fd(pathname, 2);
	}
	else if (errno == EISDIR)
	{
		ft_putstr_fd("21sh: Permission denied: ", 2);
		ft_putendl_fd(pathname, 2);
	}
	else
		ft_putendl_fd("21sh: Error file-descriptor out_redirection", 2);
}

static int	return_open_fd(t_cut_line *list, int mode)
{
	if (mode == SIMPLE_OUT_REDICTION)
		return (open(list->command_part, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	else
		return (open(list->command_part, O_CREAT | O_WRONLY | O_APPEND, 0644));
}

static int	open_fd_redirection(t_cut_line *list, char mode)
{
	int	save_fd;

	if ((save_fd = return_open_fd(list, mode)) == -1)
	{
		error_open_out(list->command_part);
		return (save_fd);
	}
	dup2(save_fd, STDOUT_FILENO);
	close(save_fd);
	return (save_fd);
}

static char	manage_mode_redirection(t_cut_line *list)
{
	if (list->special_char[1] == '>')
		return (DOUBLE_OUT_REDICTION);
	else
		return (SIMPLE_OUT_REDICTION);
}

int			browse_search_last_fd(t_cut_line *list, char mode)
{
	int	save_fd;

	save_fd = -1;
	if (list->left != NULL)
	{
		if ((save_fd = browse_search_last_fd(list->left, mode)) == -1)
			return (save_fd);
	}
	if (list->value_token == VALUE_TOKEN_COMMAND)
		save_fd = open_fd_redirection(list, mode);
	else
		mode = manage_mode_redirection(list);
	if (list->right != NULL)
	{
		close(save_fd);
		if ((save_fd = browse_search_last_fd(list->right, mode)) == -1)
			return (save_fd);
	}
	return (save_fd);
}
