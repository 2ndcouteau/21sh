/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_relative_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:06:50 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:09:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		cd_relative_path(t_env **e, char **current_pwd, char *new_path)
{
	int		new_path_len;
	int		pwd_len;

	pwd_len = ft_strlen(*current_pwd);
	new_path_len = ft_strlen(new_path);
	if ((new_path_len + pwd_len) > (PATH_MAX - 1))
		cd_set_error(e, new_path, 1);
	else
	{
		sh_add_end_path(current_pwd, new_path, pwd_len);
		cd_check_valid_file(e, current_pwd, new_path);
	}
}
