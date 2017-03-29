/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_is_cmdand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:09:33 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 17:52:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	is_cmdand(char *command_line, int start)
{
	if (command_line[start] == '&')
	{
		if (command_line[start + 1] == '&')
			return (0);
	}
	return (1);
}
