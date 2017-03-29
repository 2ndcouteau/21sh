/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_str_add_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:58:19 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 14:56:32 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	term_str_add_cpy(t_env **e, char *dst)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (dst[a] != '\0')
		a++;
	if (((*e)->tab_count->status & QUOTE) == QUOTE ||
								((*e)->tab_count->status & D_QUOTE) == D_QUOTE)
	{
		if (a < MAX_LEN_COMMAND - 2)
		{
			dst[a] = '\n';
			a++;
			x_write_position((*e)->posicao);
		}
	}
	while ((*e)->posicao->buffer_line[i] != '\0' && a < MAX_LEN_COMMAND - 1)
	{
		dst[a] = (*e)->posicao->buffer_line[i];
		a++;
		i++;
	}
	dst[a] = '\0';
}
