/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_replace_cursor_window.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:55:23 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 14:55:30 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	replace_cursor_window(int sig)
{
	t_position	*posicao;

	if (sig == SIGWINCH)
	{
		posicao = singleton_t_posicao(NULL);
		term_set_cursor_position(posicao);
		if (posicao->x_win * posicao->y_win <
								(posicao->len_command + posicao->len_prompt))
		{
			if (put_stdout("cl"))
				return ;
			ft_putstr(PROMPT);
			ft_putstr(posicao->ptr_new_tmp);
			if (posicao->x_end == 0)
				x_last_column();
			posicao->x = posicao->x_win;
			posicao->y = posicao->y_win;
			posicao->absolute_pos = posicao->len_command + posicao->len_prompt;
		}
	}
}
