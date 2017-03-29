/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_home_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 20:55:31 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 14:55:03 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	ctrl_a(t_env **e, char **new_tmp)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	while (posicao->absolute_pos > posicao->len_prompt && new_tmp)
		x_less_position(posicao);
	return (SUCCESS);
}

bool	ctrl_e(t_env **e, char **new_tmp)
{
	int			len_total;
	t_position	*posicao;

	posicao = (*e)->posicao;
	len_total = posicao->len_command + posicao->len_prompt;
	while (posicao->absolute_pos < len_total && new_tmp)
	{
		if (put_stdout("nd"))
			return (ERROR);
		x_more_position(posicao);
	}
	return (SUCCESS);
}
