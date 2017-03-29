/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_for_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:29:07 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/08 02:28:17 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char		exec_command_for_env(t_env **e, char **av)
{
	char	ret;

	if ((ret = exec_builtins(e)) == -1)
		ret = exec_system_cmd(e, av);
	return (ret);
}
