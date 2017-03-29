/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:13:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 20:56:26 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static const char *const g_cd_error[7] = {
	"",
	"File name too long",
	"cd: No such file or directory: ",
	"cd: not a directory: ",
	"cd: permission denied: ",
	"cd: OLDPWD not set",
	"cd: HOME not set",
};

void		cd_print_error(int error, char *name)
{
	if (error < 7)
	{
		ft_putstr_fd(g_cd_error[error], 2);
		ft_putendl_fd(name, 2);
	}
}
