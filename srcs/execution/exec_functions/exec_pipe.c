/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:06:26 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/11 03:32:17 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	exec_son_right(t_env **e, t_cut_line *list, char **av, int p[2])
{
	int ret;

	signal(SIGTSTP, SIG_IGN);
	dup2(p[0], STDIN_FILENO);
	close(p[1]);
	ret = exec_ast(e, list->right, av);
	env_free_all_env(e);
	if (ret == SUCCESS)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

static void	exec_son_left(t_env **e, t_cut_line *list, char **av, int p[2])
{
	int ret;

	signal(SIGTSTP, SIG_IGN);
	dup2(p[1], STDOUT_FILENO);
	close(p[0]);
	ret = exec_ast(e, list->left, av);
	env_free_all_env(e);
	if (ret == SUCCESS)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

char		exec_pipe(t_env **e, t_cut_line *list, char **av)
{
	int		p[2];
	int		pid[2];

	call_sub_signals();
	if (pipe(p) == -1)
		return (error_pipe_output());
	pid[0] = fork();
	if (pid[0] == -1)
		error_fork_output();
	else if (pid[0] == 0)
		exec_son_right(e, list, av, p);
	if ((pid[1] = fork()) == 0)
		exec_son_left(e, list, av, p);
	close(p[0]);
	close(p[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
	return (SUCCESS);
}
