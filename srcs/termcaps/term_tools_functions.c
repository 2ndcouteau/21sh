/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_tools_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:06:15 by qrosa             #+#    #+#             */
/*   Updated: 2016/06/08 13:32:16 by cristal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	x_less_position(t_position *posicao)
{
	posicao->x -= 1;
	posicao->absolute_pos -= 1;
	if (posicao->x == -1)
	{
		x_first_column(posicao);
		posicao->y -= 1;
		posicao->x = posicao->x_win - 1;
	}
	else
	{
		if (put_stdout("le"))
			exit(EXIT_FAILURE);
	}
}

void	x_more_position(t_position *posicao)
{
	posicao->x += 1;
	posicao->absolute_pos += 1;
	if (posicao->x >= posicao->x_win)
	{
		if (put_stdout("do"))
			exit(EXIT_FAILURE);
		posicao->x = 0;
		posicao->y += 1;
	}
}
