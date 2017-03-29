/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_check_back_slash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 20:53:43 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:41:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	check_back_slash(char *command_line, int start)
{
	int i;

	i = 1;
	while (((start - i) >= 0) && command_line[start - i] == 92)
		i++;
	if (command_line[start - i + 1] == 92)
	{
		if (((i - 1) % 2) == 1)
			return (1);
	}
	return (0);
}
