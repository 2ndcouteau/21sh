/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_ctrl_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 18:58:24 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:12:47 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	add_str_cpy(char *buffer_copy, char *new_tmp, char *tmp)
{
	int			i;
	int			a;

	i = 0;
	a = 0;
	while (new_tmp[i] != '\0')
	{
		tmp[i] = new_tmp[i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	while (buffer_copy[i] != '\0')
	{
		new_tmp[i] = buffer_copy[i];
		i++;
	}
	while (tmp[a] != '\0')
	{
		new_tmp[i + a] = tmp[a];
		a++;
	}
	new_tmp[i + a] = '\0';
}

bool		term_add_str(char *buffer_copy, char *new_tmp)
{
	char		*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * MAX_LEN_COMMAND)))
		exit(EXIT_FAILURE);
	add_str_cpy(buffer_copy, new_tmp, tmp);
	free(tmp);
	tmp = NULL;
	return (SUCCESS);
}

static bool	check_condition(t_position *posicao, int len_cpy)
{
	if ((len_cpy + posicao->len_full_command < MAX_LEN_COMMAND - 1 &&
	posicao->heredoc_active == 0) || (posicao->heredoc_active == 1 &&
						len_cpy + posicao->len_command < MAX_LEN_COMMAND - 1))
		return (SUCCESS);
	else
		return (ERROR);
}

bool		ctrl_y(t_env **e, char **new_tmp)
{
	t_position	*posicao;
	int			len_cpy;

	posicao = (*e)->posicao;
	len_cpy = ft_strlen(posicao->buffer_copy);
	if (!check_condition(posicao, len_cpy))
	{
		term_add_str(posicao->buffer_copy, *new_tmp +
								(posicao->absolute_pos - posicao->len_prompt));
		sh_special_putstr(*new_tmp +
								(posicao->absolute_pos - posicao->len_prompt));
		posicao->absolute_pos += len_cpy;
		posicao->len_command += len_cpy;
		if (posicao->heredoc_active == 0)
			posicao->len_full_command += len_cpy;
		term_set_cursor_position(posicao);
		if (posicao->x == 0)
		{
			x_last_column();
			posicao->y += 1;
		}
		replace_cursor(posicao);
		return (SUCCESS);
	}
	return (ERROR);
}
