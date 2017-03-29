/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_x_count_move_position.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:28:14 by qrosa             #+#    #+#             */
/*   Updated: 2016/07/23 02:22:57 by cristal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	x_write_position(t_position *posicao)
{
	posicao->x += 1;
	posicao->x_end += 1;
	posicao->len_command += 1;
	if (posicao->heredoc_active == 0)
		posicao->len_full_command += 1;
	posicao->absolute_pos += 1;
	if (posicao->x >= posicao->x_win)
	{
		posicao->x = 0;
		posicao->y += 1;
	}
	if (posicao->x_end >= posicao->x_win)
	{
		x_last_column();
		posicao->x_end = 0;
		posicao->y_end += 1;
	}
}

void	x_suppr_position(t_position *posicao)
{
	posicao->len_command -= 1;
	if (posicao->heredoc_active == 0)
		posicao->len_full_command -= 1;
	posicao->x_end -= 1;
	if (posicao->x_end == 0)
		x_last_column();
	if (posicao->x_end < 0)
	{
		posicao->x_end = posicao->x_win - 1;
		posicao->y_end -= 1;
	}
}

void	x_del_position(t_position *posicao)
{
	posicao->x_end -= 1;
	posicao->len_command -= 1;
	if (posicao->heredoc_active == 0)
		posicao->len_full_command -= 1;
	if (posicao->x_end == 0)
		x_last_column();
	if (posicao->x_end < 0)
	{
		posicao->x_end = posicao->x_win - 1;
		posicao->y_end -= 1;
	}
}
