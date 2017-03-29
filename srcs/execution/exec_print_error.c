/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_print_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:50:27 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/04 22:41:55 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static const char *const g_exec_error_message[4] = {
	"",
	"21sh: Command not found: ",
	"21sh: ",
	"21sh: Access Denied: "
};

void		exec_print_error(int error, char *name)
{
	ft_putstr_fd(g_exec_error_message[error], 2);
	ft_putendl_fd(name, 2);
}
