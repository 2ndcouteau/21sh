/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_ctrl_k.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 18:25:27 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:04:52 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	save_clean_part(t_position *posicao, char *new_tmp)
{
	int			i;

	i = 0;
	ft_bzero(posicao->buffer_copy, MAX_LEN_COMMAND);
	while (new_tmp[i] != '\0')
	{
		posicao->buffer_copy[i] = new_tmp[i];
		new_tmp[i] = '\0';
		i++;
	}
	posicao->buffer_copy[i] = '\0';
	posicao->len_command -= i;
	if (posicao->heredoc_active == 0)
		posicao->len_full_command -= i;
}

bool	ctrl_k(t_env **e, char **new_tmp)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	if (posicao->absolute_pos < (posicao->len_prompt + posicao->len_command))
	{
		if (put_stdout("cd"))
			return (ERROR);
		save_clean_part(posicao, *new_tmp + posicao->absolute_pos -
														posicao->len_prompt);
		posicao->x_end = posicao->x;
		posicao->y_end = posicao->y;
		posicao->absolute_pos = ((posicao->x_win * posicao->y_end) +
																	posicao->x);
		return (SUCCESS);
	}
	return (ERROR);
}
