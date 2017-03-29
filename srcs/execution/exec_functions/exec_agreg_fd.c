/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_agreg_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:05:32 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/11 17:54:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	check_in_agreg(char *special_char)
{
	if (*special_char != '>')
		return (ft_atoi(special_char));
	return (-1);
}

static int	check_out_agreg(char *special_char)
{
	while (*special_char != '&')
		special_char++;
	special_char++;
	if (ft_isdigit(*special_char))
		return (ft_atoi(special_char));
	if (*special_char == ' ')
		return (1);
	return (-1);
}

static int	check_dash(char *special_char)
{
	while (*special_char != '&')
		special_char++;
	special_char++;
	if (*special_char == '-')
		return (1);
	return (0);
}

static int	restore_fd(int in, int out, int save_fd, int mark)
{
	if (save_fd != -1 && in != -1 && mark == 0)
	{
		dup2(save_fd, out);
		if (close(save_fd) == -1)
			return (ERROR);
	}
	else if (mark == 1 && in != -1)
	{
		dup2(save_fd, in);
		if (close(save_fd) == -1)
			return (ERROR);
	}
	return (ERROR);
}

char		exec_agreg_fd(t_env **e, t_cut_line *list, char **av)
{
	int	in;
	int	out;
	int	save_fd;
	int	mark;

	out = 1;
	in = check_in_agreg(list->special_char);
	if ((mark = check_dash(list->special_char)) != 1)
		out = check_out_agreg(list->special_char);
	if (mark == 1)
		save_fd = dup(in);
	else if (out != -1 && in != -1)
		save_fd = dup(out);
	else
		save_fd = -1;
	if (in != -1 && out != -1)
	{
		if (mark == 1)
			close(in);
		else
			dup2(out, in);
	}
	exec_ast(e, list->left, av);
	return (restore_fd(in, out, save_fd, mark));
}
