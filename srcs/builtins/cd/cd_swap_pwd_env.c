/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_swap_pwd_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:54:36 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 19:05:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	cpy_pwd(t_env **e, char **current_pwd, int oldpwd_pos)
{
	int		pwd_pos;

	if ((pwd_pos = env_position_line(e, "PWD=", 4)) >= 0)
	{
		env_replace_var((*e)->env, "OLDPWD=", (*e)->env[pwd_pos] + 4,
	oldpwd_pos);
		env_replace_var((*e)->env, "PWD=", *current_pwd, pwd_pos);
	}
	else
	{
		setenv_var(e, "PWD", *current_pwd);
	}
}

static void	set_and_cpy_pwd(t_env **e, char **current_pwd)
{
	int		pwd_pos;

	if ((pwd_pos = env_position_line(e, "PWD=", 4)) >= 0)
	{
		setenv_var(e, "OLDPWD", (*e)->env[pwd_pos] + 4);
		env_replace_var((*e)->env, "PWD=", *current_pwd, pwd_pos);
	}
	else
	{
		setenv_var(e, "PWD", *current_pwd);
		setenv_var(e, "OLDPWD", *current_pwd);
	}
}

void		cd_swap_pwd_env(t_env **e, char **current_pwd, t_opt **cd_opt)
{
	int		oldpwd_pos;

	if (opt_check_last_opt((*cd_opt)->opt_all, 'L', 'P') == 1)
	{
		ft_bzero(*current_pwd, PATH_MAX);
		getcwd(*current_pwd, PATH_MAX);
	}
	else
	{
		cd_clean_path(current_pwd);
	}
	if ((oldpwd_pos = env_position_line(e, "OLDPWD=", 7)) >= 0)
		cpy_pwd(e, current_pwd, oldpwd_pos);
	else
		set_and_cpy_pwd(e, current_pwd);
}
