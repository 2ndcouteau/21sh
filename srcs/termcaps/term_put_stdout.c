/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_put_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:36:16 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 14:56:06 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	my_outc(int c)
{
	return ((int)write(STDOUT_FILENO, &c, 1));
}

bool		put_stdout(char *opt)
{
	char	*res;

	if ((res = tgetstr(opt, NULL)) == NULL)
		return (1);
	tputs(res, 0, my_outc);
	return (0);
}
