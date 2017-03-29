/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_arrow_move_cursor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:33:39 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 14:57:30 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	arrow_left(t_env **e, char **new_tmp)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	if (posicao->absolute_pos > posicao->len_prompt && new_tmp)
		x_less_position(posicao);
	else
		put_stdout("bl");
	return (SUCCESS);
}

bool	arrow_right(t_env **e, char **new_tmp)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	if ((posicao->y < posicao->y_end) || (posicao->y == posicao->y_end &&
										posicao->x < posicao->x_end && new_tmp))
	{
		if (put_stdout("nd"))
			return (ERROR);
		x_more_position(posicao);
	}
	else
		put_stdout("bl");
	return (SUCCESS);
}
