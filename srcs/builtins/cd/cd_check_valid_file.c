/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_check_valid_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:38:50 by qrosa             #+#    #+#             */
/*   Updated: 2016/11/14 16:23:04 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	cd_check_valid_file(t_env **e, char **current_pwd,
	char *name)
{
	struct stat	t_stat;
	char		check;

	if (lstat(*current_pwd, &t_stat) >= 0)
	{
		check = ft_check_typefile(t_stat.st_mode & S_IFMT);
		if (check == 'd' || check == 'l')
		{
			if (access(*current_pwd, X_OK) == 0)
				return (SUCCESS);
			else
				cd_set_error(e, name, 4);
		}
		else
			cd_set_error(e, name, 3);
	}
	else
		cd_set_error(e, name, 2);
	return (ERROR);
}
