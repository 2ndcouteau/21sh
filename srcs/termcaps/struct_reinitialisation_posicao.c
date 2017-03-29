/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_reinitialisation_posicao.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:56:46 by qrosa             #+#    #+#             */
/*   Updated: 2016/07/28 10:56:54 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	reinitialisation_posicao(t_env **e)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	posicao->len_prompt = ft_strlen(PROMPT);
	posicao->absolute_pos = posicao->len_prompt;
	posicao->len_command = 0;
	posicao->len_full_command = 0;
	posicao->heredoc_active = 0;
	posicao->x = 0;
	posicao->y = 0;
	posicao->x_end = 0;
	posicao->y_end = 0;
	posicao->x_win = 0;
	posicao->y_win = 0;
	(*e)->posicao->waiting_mode = 0;
}
