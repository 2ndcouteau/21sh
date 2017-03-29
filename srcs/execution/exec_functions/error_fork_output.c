/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fork_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:47:31 by qrosa             #+#    #+#             */
/*   Updated: 2016/12/01 15:31:43 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	error_fork_output(void)
{
	ft_putendl_fd("\"21sh\": fork failed: ressource temporaly unavailable.", 1);
	return (ERROR);
}
