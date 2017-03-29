/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_alt_move_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 20:48:42 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 15:06:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	alt_up(t_env **e, char **new_tmp)
{
	int			i;
	t_position	*posicao;

	i = 0;
	posicao = (*e)->posicao;
	if (posicao->y > 0 && new_tmp)
	{
		if ((posicao->y == 1 && (posicao->x >= posicao->len_prompt)) ||
																posicao->y > 1)
		{
			while (i < posicao->x_win)
			{
				arrow_left(e, new_tmp);
				i++;
			}
		}
		else
		{
			while (posicao->x != posicao->len_prompt)
				arrow_left(e, new_tmp);
		}
	}
	return (SUCCESS);
}

bool	alt_down(t_env **e, char **new_tmp)
{
	int			i;
	t_position	*posicao;

	i = 0;
	posicao = (*e)->posicao;
	if (posicao->y < posicao->y_end && new_tmp)
	{
		if (((posicao->y == posicao->y_end - 1) &&
			posicao->x <= posicao->x_end) || (posicao->y < posicao->y_end - 1))
		{
			while (i < posicao->x_win)
			{
				arrow_right(e, new_tmp);
				i++;
			}
		}
		else
		{
			while (posicao->x != posicao->x_end)
				arrow_right(e, new_tmp);
		}
	}
	return (SUCCESS);
}
