/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_echo_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:17:04 by qrosa             #+#    #+#             */
/*   Updated: 2016/09/09 16:17:12 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	print_echo_line(t_env **e, unsigned int tab_position, short options)
{
	if (!print_long_options(options))
		return ;
	if ((options & 1) != 1)
		print_direct_line(e, tab_position, options);
	else
		print_special_line(e, tab_position, options);
}
