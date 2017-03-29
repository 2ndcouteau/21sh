/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_set_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:53:00 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 19:06:02 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		cd_set_error(t_env **e, char *name, int nbr)
{
	(*e)->current_cmd->error_name = ft_strdup(name);
	(*e)->current_cmd->error_nbr = nbr;
}
