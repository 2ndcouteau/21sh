/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:26:36 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 19:05:05 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static const char *const	g_error_message[NB_ERROR] = {
	"\"21sh\" takes no arguments\n  --  Just use : ./21sh",
	"The shell has quit.\n -- Please restart the Shell -- ",
	"usage: env [-i] [utility [argument...]",
	"setenv: Variable name must begin with a letter or '_'.",
	"setenv: Variable name must contain alphanumeric characters or '_'."
};

void						sh_print_error(int error, char *name)
{
	if (error > 0 && error < NB_ERROR)
		ft_putendl_fd(g_error_message[error], 2);
	else if (error == -1)
	{
		ft_putstr_fd("21sh: Command not found: ", 2);
		ft_putendl_fd(name, 2);
	}
	else if (error == -2)
	{
		ft_putstr_fd("21sh: syntax error near unexpected token '", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd("\'", 2);
	}
	else if (error == -3)
	{
		ft_putstr_fd("21sh: ", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": Ambigous redirect", 2);
	}
}
