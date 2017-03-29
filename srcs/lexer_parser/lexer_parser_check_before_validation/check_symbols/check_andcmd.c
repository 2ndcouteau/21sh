/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_andcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:37:52 by qrosa             #+#    #+#             */
/*   Updated: 2016/11/05 22:07:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

int		check_andcmd(t_count *tab_count, char *command_line, int i)
{
	if (command_line[i + 1] == '&')
		tab_count->heredoc_active = 0;
	return (0);
}
