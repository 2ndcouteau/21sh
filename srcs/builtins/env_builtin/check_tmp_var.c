/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tmp_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:46:16 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:00:53 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

int			check_tmp_var(t_env **e, int cpt)
{
	int	len;
	int	ret;

	ret = cpt;
	while ((*e)->current_cmd->split_line[cpt] != NULL)
	{
		len = 0;
		while ((*e)->current_cmd->split_line[cpt][len] != '=' &&
								(*e)->current_cmd->split_line[cpt][len] != '\0')
			++len;
		if ((*e)->current_cmd->split_line[cpt][len] == '=')
			++cpt;
		else
			return (cpt - ret);
	}
	return (cpt - ret);
}
