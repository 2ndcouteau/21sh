/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_oldpwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:47:04 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:09:19 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		cd_oldpwd(t_env **e, char **current_pwd)
{
	int		oldpwd_pos;
	int		oldpwd_len;

	if ((oldpwd_pos = env_position_line(e, "OLDPWD=", 7)) >= 0)
	{
		oldpwd_len = ft_strlen((*e)->env[oldpwd_pos] + 7);
		ft_bzero(*current_pwd, PATH_MAX);
		*current_pwd = ft_strncpy(*current_pwd, (*e)->env[oldpwd_pos] + 7,
	oldpwd_len);
		cd_check_valid_file(e, current_pwd, *current_pwd);
	}
	else
		cd_set_error(e, "", 5);
}
