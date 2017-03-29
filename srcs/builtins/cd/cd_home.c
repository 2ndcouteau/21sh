/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:16:56 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/05 00:15:01 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		cd_home(t_env **e, char **current_pwd, char *new_path)
{
	int		home_pos;
	int		pwd_len;
	int		new_path_len;

	if (new_path[0] == '/')
		new_path++;
	if ((home_pos = env_position_line(e, "HOME=", 5)) >= 0)
	{
		pwd_len = ft_strlen((*e)->env[home_pos] + 5);
		new_path_len = ft_strlen(new_path) - 1;
		if ((new_path_len + pwd_len) > (PATH_MAX - 1))
			cd_set_error(e, new_path, 1);
		else
		{
			ft_bzero(*current_pwd, PATH_MAX);
			*current_pwd = ft_strncpy(*current_pwd, (*e)->env[home_pos] + 5,
	pwd_len);
			sh_add_end_path(current_pwd, new_path, pwd_len);
			cd_check_valid_file(e, current_pwd, *current_pwd);
		}
	}
	else
		cd_set_error(e, "", 6);
}
