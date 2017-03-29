/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_set_cursor_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 11:01:38 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:14:26 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	term_set_cursor_position(t_position *posicao)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	posicao->x_end = (posicao->len_prompt + posicao->len_command) % w.ws_col;
	posicao->y_end = (posicao->len_prompt + posicao->len_command) / w.ws_col;
	posicao->y = (posicao->absolute_pos) / w.ws_col;
	posicao->x = (posicao->absolute_pos) % w.ws_col;
	if (posicao->y == 0 && posicao->x <= posicao->len_prompt)
		posicao->x = posicao->len_prompt;
	posicao->x_win = w.ws_col;
	posicao->y_win = w.ws_row;
}
