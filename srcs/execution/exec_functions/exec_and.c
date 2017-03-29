/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:03:57 by qrosa             #+#    #+#             */
/*   Updated: 2016/11/30 18:04:06 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	exec_and(t_env **e, t_cut_line *list, char **av)
{
	char	ret;

	ret = ERROR;
	if (exec_ast(e, list->left, av) == SUCCESS)
		ret = exec_ast(e, list->right, av);
	return (ret);
}
