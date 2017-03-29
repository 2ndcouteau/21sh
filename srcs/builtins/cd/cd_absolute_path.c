/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_absolute_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:07:23 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:08:41 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	cd_absolute_path(t_env **e, char **current_pwd, char *new_path)
{
	int		new_path_len;

	new_path_len = ft_strlen(new_path);
	if (new_path_len > (PATH_MAX - 1))
		cd_set_error(e, new_path, 1);
	else
	{
		ft_bzero(*current_pwd, PATH_MAX);
		*current_pwd = ft_strncpy(*current_pwd, new_path, new_path_len);
		cd_check_valid_file(e, current_pwd, new_path);
	}
}
