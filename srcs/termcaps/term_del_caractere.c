/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_del_caractere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:43:05 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:05:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	term_del_caractere(char *new_tmp)
{
	int		i;

	i = 0;
	while (new_tmp[i] != '\0')
	{
		new_tmp[i] = new_tmp[i + 1];
		i++;
	}
}

bool		del(t_env **e, char **new_tmp)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	if (posicao->absolute_pos - posicao->len_prompt < posicao->len_command &&
																		new_tmp)
	{
		term_del_caractere(*new_tmp +
							((posicao->absolute_pos) - posicao->len_prompt));
		if (put_stdout("cd"))
			return (ERROR);
		sh_special_putstr(*new_tmp +
								(posicao->absolute_pos - posicao->len_prompt));
		x_del_position(posicao);
		replace_cursor(posicao);
	}
	return (SUCCESS);
}
