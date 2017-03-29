/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipe_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:03:13 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:02:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	error_pipe_output(void)
{
	ft_putendl_fd(
	"\"21sh\": pipe failed. Too many Open files or file desciptors in use", 1);
	return (ERROR);
}
