/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_alt_move_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 23:29:06 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 17:58:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	move_to_next_word(t_env **e, char **new_tmp, int i)
{
	while (i >= 0)
	{
		arrow_right(e, new_tmp);
		i--;
	}
}

bool		alt_right(t_env **e, char **new_tmp)
{
	int			i;
	int			start_pos;
	t_position	*posicao;

	i = 0;
	posicao = (*e)->posicao;
	start_pos = posicao->absolute_pos - posicao->len_prompt;
	while ((*new_tmp)[start_pos + i] != '\0')
	{
		if ((*new_tmp)[start_pos + i] != ' ')
		{
			while (ft_isprint((*new_tmp)[start_pos + i + 1]) &&
										(*new_tmp)[start_pos + i + 1] != ' ' &&
										(*new_tmp)[start_pos + i + 1] != '\0')
				i++;
			move_to_next_word(e, new_tmp, i);
			return (SUCCESS);
		}
		i++;
	}
	return (ERROR);
}

static void	move_to_previous_word(t_env **e, char **new_tmp, int i)
{
	while (i > 0)
	{
		arrow_left(e, new_tmp);
		i--;
	}
}

bool		alt_left(t_env **e, char **new_tmp)
{
	int			i;
	int			start_pos;
	t_position	*posicao;

	i = 1;
	posicao = (*e)->posicao;
	start_pos = posicao->absolute_pos - posicao->len_prompt;
	while (start_pos - i >= 0)
	{
		if ((ft_isprint((*new_tmp)[start_pos - i]) &&
						(*new_tmp)[start_pos - i] != ' ') || start_pos - i == 0)
		{
			while ((start_pos - i) > 0 &&
										(*new_tmp)[start_pos - i - 1] != ' ')
				i++;
			move_to_previous_word(e, new_tmp, i);
			return (SUCCESS);
		}
		i++;
	}
	return (ERROR);
}
