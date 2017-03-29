/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexpar_init_tab_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:12:49 by qrosa             #+#    #+#             */
/*   Updated: 2016/10/08 16:35:10 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void				init_tab_count(t_count *tab_count)
{
	tab_count->status = 0;
	ft_bzero(tab_count->order_line, (MAX_LEN_COMMAND / 2));
	tab_count->order_position = 0;
	tab_count->heredoc_active = 0;
	tab_count->back_slash = 0;
	tab_count->diese = 0;
	tab_count->parentheses = 0;
	tab_count->braces = 0;
	tab_count->brackets = 0;
	tab_count->error = 0;
}
