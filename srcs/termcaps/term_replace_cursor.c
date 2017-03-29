/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_replace_cursor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:08:19 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:11:11 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	go_left(int offset)
{
	while (offset != 0)
	{
		if (put_stdout("le"))
			exit(EXIT_FAILURE);
		offset--;
	}
}

static void	go_right(int offset)
{
	while (offset != 0)
	{
		if (put_stdout("nd"))
			exit(EXIT_FAILURE);
		offset--;
	}
}

static void	go_up(int offset)
{
	while (offset != 0)
	{
		if (put_stdout("up"))
			exit(EXIT_FAILURE);
		offset--;
	}
}

void		replace_cursor(t_position *posicao)
{
	int		offset;

	if (posicao->x_end > posicao->x)
	{
		offset = posicao->x_end - posicao->x;
		go_left(offset);
	}
	else if (posicao->x_end < posicao->x)
	{
		offset = posicao->x - posicao->x_end;
		go_right(offset);
	}
	if (posicao->y_end > posicao->y)
	{
		offset = posicao->y_end - posicao->y;
		go_up(offset);
	}
}
