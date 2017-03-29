/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_ctrl_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:26:50 by qrosa             #+#    #+#             */
/*   Updated: 2016/07/13 01:11:59 by cristal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	ctrl_l(t_env **e, char **new_tmp)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	if (put_stdout("cl"))
		return (ERROR);
	if ((*e)->posicao->waiting_mode == 0)
		ft_putstr(PROMPT);
	else
		print_waiting_prompt((*e)->tab_count, 0);
	sh_special_putstr(*new_tmp);
	if (posicao->x_end == 0)
		x_last_column();
	replace_cursor(posicao);
	return (SUCCESS);
}
