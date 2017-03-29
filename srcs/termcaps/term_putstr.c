/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 20:20:07 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 15:06:00 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	term_putstr(t_position *posicao, char **new_tmp)
{
	int	len_available;

	len_available = (posicao->x_win * posicao->y_win) - posicao->len_prompt - 7;
	ft_putstr(PROMPT);
	ft_putnstr(*new_tmp, len_available);
	ft_putstr(" <.... ");
	posicao->absolute_pos = (posicao->x_win * posicao->y_win) - 1;
	posicao->x = posicao->x_win - 1;
	posicao->y = posicao->y_win - 1;
}
