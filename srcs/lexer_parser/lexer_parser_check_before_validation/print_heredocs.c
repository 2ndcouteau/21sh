/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:15:57 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:34:45 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	print_heredocs(t_count *tab_count)
{
	if ((tab_count->status & D_REDICTION_STDIN) == D_REDICTION_STDIN)
	{
		ft_putstr("heredoc : ");
		ft_putstr(tab_count->check_position_heredoc->word);
		ft_putstr(" > ");
		tab_count->len_waiting_prompt =
						13 + ft_strlen(tab_count->check_position_heredoc->word);
		return (SUCCESS);
	}
	return (ERROR);
}
