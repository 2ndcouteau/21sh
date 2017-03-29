/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_exec_add_caractere.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 00:16:33 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:12:29 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool	term_isprint_key(long int *buff_convert)
{
	if (*buff_convert >= 32 && *buff_convert <= 126)
		return (SUCCESS);
	return (ERROR);
}

static bool	term_can_write(t_env **e, t_position *posicao)
{
	if (posicao->heredoc_active == 0)
	{
		if (((*e)->tab_count->status & QUOTE) == QUOTE ||
								((*e)->tab_count->status & D_QUOTE) == D_QUOTE)
		{
			if (posicao->len_full_command < MAX_LEN_COMMAND - 2)
				return (SUCCESS);
		}
		else if (posicao->len_full_command < MAX_LEN_COMMAND - 1)
			return (SUCCESS);
	}
	else if (posicao->heredoc_active == 1 && posicao->len_command <
															MAX_LEN_COMMAND - 1)
		return (SUCCESS);
	return (ERROR);
}

static bool	term_add_caractere(t_env **e, char *buffer, t_position *posicao,
																char *new_tmp)
{
	char	char_tmp1;
	char	char_tmp2;
	int		i;

	i = 0;
	if (!term_can_write(e, posicao))
	{
		char_tmp1 = buffer[0];
		while (new_tmp[i] != '\0')
		{
			char_tmp2 = new_tmp[i];
			new_tmp[i] = char_tmp1;
			char_tmp1 = char_tmp2;
			i++;
		}
		new_tmp[i] = char_tmp1;
		new_tmp[i + 1] = '\0';
		return (SUCCESS);
	}
	return (ERROR);
}

bool		exec_term_add_caractere(char *buffer, long int *buff_convert,
													t_env **e, char *new_tmp)
{
	int			start_position;
	t_position	*posicao;

	posicao = (*e)->posicao;
	start_position = posicao->absolute_pos - posicao->len_prompt;
	if (!term_isprint_key(buff_convert))
	{
		if (!term_add_caractere(e, buffer, posicao, new_tmp + start_position))
		{
			if (put_stdout("cd"))
				return (ERROR);
			sh_special_putstr(new_tmp + start_position);
			x_write_position(posicao);
			replace_cursor(posicao);
			return (SUCCESS);
		}
	}
	return (ERROR);
}
