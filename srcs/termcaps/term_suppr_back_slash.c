/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_suppr_back_slash.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 11:02:44 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 11:47:13 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	suppr_back_slash(char *command_line, t_position *posicao,
															t_count *tab_count)
{
	int	i;

	i = 0;
	if (tab_count->heredoc_mode != HEREDOC_ACTIVE)
	{
		while (command_line[i] != '\0')
			i++;
		if (i > 0 && tab_count->back_slash == 1)
		{
			command_line[i - 1] = '\0';
			posicao->len_command -= 1;
			posicao->len_full_command -= 1;
		}
	}
}
