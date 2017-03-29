/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_check_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:21:07 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 13:21:20 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	term_check_input(t_env **e, char *buffer, char *new_tmp)
{
	long int	*buff_convert;

	buff_convert = (int long *)buffer;
	if (!exec_term_add_caractere(buffer, buff_convert, e, new_tmp))
		return (SUCCESS);
	if (!exec_term_command_edition(buff_convert, e, &new_tmp))
		return (SUCCESS);
	if (!exec_term_command_cursor(buff_convert, e, &new_tmp))
		return (SUCCESS);
	put_stdout("bl");
	return (ERROR);
}
