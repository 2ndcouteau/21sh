/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:02:58 by qrosa             #+#    #+#             */
/*   Updated: 2016/11/30 18:03:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	exec_or(t_env **e, t_cut_line *list, char **av)
{
	char	ret;

	ret = SUCCESS;
	if (exec_ast(e, list->left, av) == ERROR)
		ret = exec_ast(e, list->right, av);
	return (ret);
}
