/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:26:42 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:31:02 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	restore_fd(int p[2], int p_save[2])
{
	close(p[0]);
	dup2(p_save[0], STDIN_FILENO);
	dup2(p_save[1], STDOUT_FILENO);
	close(p_save[0]);
	close(p_save[1]);
}

static char	failed_son_execution(int p[2], int p_save[2])
{
	restore_fd(p, p_save);
	return (ERROR);
}

void		free_node_heredoc(t_env **e)
{
	t_heredoc *tmp;

	tmp = (*e)->tab_count->begin_list_heredoc;
	if ((*e)->tab_count != NULL)
	{
		if (tmp != NULL)
		{
			(*e)->tab_count->begin_list_heredoc =
									(*e)->tab_count->begin_list_heredoc->next;
			if (tmp->word != NULL)
				tmp->word = ft_free_line(&(tmp->word));
			if (tmp->save_text != NULL)
				tmp->save_text = ft_free_line(&(tmp->save_text));
			free(tmp);
			tmp = NULL;
		}
	}
}

static void	exec_son_heredoc(t_env **e, int p[2])
{
	dup2(p[1], STDOUT_FILENO);
	close(p[0]);
	ft_putendl_fd((*e)->tab_count->begin_list_heredoc->save_text, p[1]);
	close(p[1]);
	env_free_all_env(e);
	exit(EXIT_SUCCESS);
}

char		exec_heredoc(t_env **e, t_cut_line *list, char **av)
{
	int			p[2];
	pid_t		pid;
	int			status;
	int			p_save[2];

	p_save[1] = dup(STDOUT_FILENO);
	p_save[0] = dup(STDIN_FILENO);
	if (pipe(p) == -1)
		return (error_pipe_output());
	if ((pid = fork()) == -1)
		return (error_fork_output());
	if (pid == 0)
		exec_son_heredoc(e, p);
	else
	{
		dup2(p[0], STDIN_FILENO);
		close(p[1]);
		waitpid(-1, &status, 0);
		if (exec_return_status(status))
			return (failed_son_execution(p, p_save));
		free_node_heredoc(e);
		exec_ast(e, list->left, av);
		restore_fd(p, p_save);
	}
	return (SUCCESS);
}
