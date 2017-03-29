/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_position_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 22:58:58 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/05 12:08:44 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

int		env_position_line(t_env **e, char *var_e, int len)
{
	int		cpt;
	char	mark;

	cpt = 0;
	mark = 0;
	if (var_e[0] == '$')
	{
		mark = 1;
		++var_e;
	}
	if ((*e)->env != NULL)
	{
		while ((*e)->env[cpt] != NULL)
		{
			if (ft_strncmp((*e)->env[cpt], var_e, len) == 0)
			{
				if ((mark == 1 && (*e)->env[cpt][len] == '=') || mark == 0)
					return (cpt);
			}
			cpt++;
		}
	}
	return (-1);
}
