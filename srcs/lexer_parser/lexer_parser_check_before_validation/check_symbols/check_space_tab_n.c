/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_tab_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:31:16 by qrosa             #+#    #+#             */
/*   Updated: 2016/11/05 22:07:34 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	check_space_tab_n(t_count *tab_count)
{
	if (tab_count->heredoc_active == 1)
	{
		if (tab_count->trim_space == 1)
			tab_count->heredoc_active = 0;
	}
}
