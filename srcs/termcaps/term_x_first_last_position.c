/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_x_last_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:29:12 by qrosa             #+#    #+#             */
/*   Updated: 2016/06/08 13:29:06 by cristal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	x_last_column(void)
{
	ft_putchar_fd(' ', 1);
	if (put_stdout("le"))
		exit(EXIT_FAILURE);
}

void	x_first_column(t_position *posicao)
{
	int i;

	i = 0;
	if (put_stdout("up"))
		exit(EXIT_FAILURE);
	while (i < posicao->x_win)
	{
		if (put_stdout("nd"))
			exit(EXIT_FAILURE);
		i++;
	}
}
