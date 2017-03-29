/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:27:41 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 13:29:32 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	(*g_exec_sign_functions[NB_SIGN_EXEC])(t_env **e, t_cut_line *list,
																	char **av) =
{
	exec_command,
	exec_semi_colon,
	exec_and,
	exec_or,
	exec_pipe,
	exec_redirection,
	exec_redirection,
	exec_agreg_fd
};

char	exec_ast(t_env **e, t_cut_line *list, char **av)
{
	if (list != NULL)
		return (g_exec_sign_functions[list->value_token](e, list, av));
	return (-1);
}
