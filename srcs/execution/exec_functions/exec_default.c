/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:04:56 by qrosa             #+#    #+#             */
/*   Updated: 2016/12/05 13:18:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	exec_default(t_env **e, t_cut_line *list, char **av)
{
	exec_ast(e, list->left, av);
	exec_ast(e, list->right, av);
	return (SUCCESS);
}
