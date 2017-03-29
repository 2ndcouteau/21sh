/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_suppr_caractere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:19:52 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 13:25:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	term_suppr_caractere(t_position *posicao, char *new_tmp,
															int start_position)
{
	int			i;
	int			len_end_position;

	i = 0;
	len_end_position = posicao->len_command - start_position;
	while (i <= len_end_position)
	{
		new_tmp[i] = new_tmp[i + 1];
		i++;
	}
	new_tmp[i] = '\0';
	ft_bzero(new_tmp + i, MAX_LEN_COMMAND - (start_position + i));
}

bool		suppr(t_env **e, char **new_tmp)
{
	int			start_position;
	t_position	*posicao;

	posicao = (*e)->posicao;
	if (posicao->absolute_pos - posicao->len_prompt > 0 && new_tmp)
	{
		start_position = posicao->absolute_pos - posicao->len_prompt - 1;
		term_suppr_caractere(posicao, *new_tmp + start_position,
																start_position);
		arrow_left(e, new_tmp);
		if (put_stdout("cd"))
			return (ERROR);
		sh_special_putstr(*new_tmp + start_position);
		x_suppr_position(posicao);
		replace_cursor(posicao);
	}
	return (SUCCESS);
}
