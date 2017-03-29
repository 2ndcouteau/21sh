/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_ctrl_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:19:21 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/10 20:54:25 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	ctrl_d(t_env **e, char **new_tmp)
{
	if ((*e)->posicao->len_full_command == 0 && new_tmp)
		exit_builtin(e);
	return (ERROR);
}
