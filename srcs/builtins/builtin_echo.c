/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 22:02:44 by yoko              #+#    #+#             */
/*   Updated: 2017/02/09 15:18:04 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

/*
** Options values :
** 0 = E;
** 1 = e;
** 2 = n;
** 4 = help;
** 8 = version;
*/

char	echo_builtin(t_env **e)
{
	unsigned int	tab_position;
	short			options;

	options = 0;
	tab_position = check_option_echo(e, &options);
	print_echo_line(e, tab_position, options);
	return (SUCCESS);
}
