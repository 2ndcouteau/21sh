/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_new_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:43:11 by yoko              #+#    #+#             */
/*   Updated: 2017/02/09 16:28:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	check_new_cmd(t_cut_line *browse_tmp)
{
	if (browse_tmp != NULL)
	{
		if (browse_tmp->value_token <= VALUE_TOKEN_PIPE &&
							browse_tmp->value_token >= VALUE_TOKEN_SEMICOLON)
			return (0);
	}
	return (1);
}
