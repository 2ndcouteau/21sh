/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_ctrl_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 18:25:27 by qrosa             #+#    #+#             */
/*   Updated: 2016/07/23 02:18:53 by cristal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	ctrl_u(t_env **e, char **new_tmp)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	if (*new_tmp[0] == '\0')
		return (ERROR);
	ctrl_a(e, new_tmp);
	if (put_stdout("cd"))
		return (ERROR);
	ft_strcpy(posicao->buffer_copy, *new_tmp);
	ft_bzero(*new_tmp, MAX_LEN_COMMAND);
	if (posicao->heredoc_active == 0)
		posicao->len_full_command -= posicao->len_command;
	posicao->len_command = 0;
	posicao->absolute_pos = posicao->len_prompt;
	term_set_cursor_position(posicao);
	return (SUCCESS);
}
