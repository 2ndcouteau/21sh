/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_exec_command_cursor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:05:32 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 13:18:49 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool						(*g_term_command_cursor[NB_TERM_COMMAND_CURSOR])
												(t_env **e, char **new_tmp) =
{
	ctrl_a,
	ctrl_d,
	ctrl_e,
	ctrl_l,
	arrow_up,
	arrow_down,
	arrow_right,
	arrow_left,
	ctrl_e,
	ctrl_a,
	alt_up,
	alt_down,
	alt_right,
	alt_left,
	alt_up,
	alt_down,
	alt_right,
	alt_left
};

static const long int	g_term_value_cursor[NB_TERM_COMMAND_CURSOR] = {
	1,
	4,
	5,
	12,
	4283163,
	4348699,
	4414235,
	4479771,
	4610843,
	4741915,
	1096489755,
	1113266971,
	1130044187,
	1146821403,
	71688292227867,
	72787803855643,
	73887315483419,
	74986827111195
};

bool	exec_term_command_cursor(long int *buff_convert,
													t_env **e, char **new_tmp)
{
	int	cpt;

	cpt = 0;
	if (ft_strcmp((char*)buff_convert, "\0") == 0)
		return (ERROR);
	while (cpt < NB_TERM_COMMAND_CURSOR)
	{
		if (*buff_convert == g_term_value_cursor[cpt])
		{
			if (g_term_command_cursor[cpt](e, new_tmp))
				return (ERROR);
			return (SUCCESS);
		}
		cpt++;
	}
	return (ERROR);
}
