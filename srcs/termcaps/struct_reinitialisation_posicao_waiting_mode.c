/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_reinitialisation_posicao_waiting_mode.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:59:30 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:57:27 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		reinitialisation_posicao_waiting_mode(t_position *posicao,
															t_count *tab_count)
{
	posicao->len_prompt = tab_count->len_waiting_prompt;
	posicao->absolute_pos = posicao->len_prompt;
	posicao->len_command = 0;
	posicao->x = 0;
	posicao->y = 0;
	posicao->x_end = 0;
	posicao->y_end = 0;
	posicao->x_win = 0;
	posicao->y_win = 0;
	posicao->waiting_mode = 1;
}
