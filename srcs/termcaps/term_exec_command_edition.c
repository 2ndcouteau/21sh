/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_exec_command_edition.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:03:53 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 13:19:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool					(*g_term_command_edition[NB_TERM_COMMAND_EDITION])
												(t_env **e, char **new_tmp) =
{
	ctrl_k,
	ctrl_u,
	ctrl_y,
	echap,
	suppr,
	del
};

static const long int	g_term_value_edition[NB_TERM_COMMAND_EDITION] = {
	11,
	21,
	25,
	27,
	127,
	2117294875
};

bool	exec_term_command_edition(long int *buff_convert,
													t_env **e, char **new_tmp)
{
	int	cpt;

	cpt = 0;
	while (cpt < NB_TERM_COMMAND_EDITION)
	{
		if (*buff_convert == g_term_value_edition[cpt])
		{
			if (g_term_command_edition[cpt](e, new_tmp))
				return (ERROR);
			return (SUCCESS);
		}
		cpt++;
	}
	return (ERROR);
}
