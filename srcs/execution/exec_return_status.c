/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_return_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:22:24 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 11:07:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

int	exec_return_status(int status)
{
	return (!(WIFEXITED(status) && !WIFSIGNALED(status) &&
														!WEXITSTATUS(status)));
}
