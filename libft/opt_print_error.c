/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_print_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/02/09 22:55:54 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	Don't forget to adapt the message for your program !
**	---------------------------------------------------
**	1 - ERROR MALLOC
**	2 - For short options
**	3 - For long options
*/

static void	print_short_error(t_opt **e)
{
	ft_putstr_fd((*e)->define[0], 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd((*e)->bad_char, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd((*e)->define[0], 2);
	ft_putstr_fd((*e)->define[3], 2);
	ft_putstr_fd((*e)->define[4], 2);
	ft_putendl_fd((*e)->define[5], 2);
}

static void	print_long_error(char **argv, t_opt **e)
{
	ft_putstr_fd((*e)->define[0], 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putstr_fd(argv[(*e)->position - 1] + 2, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd((*e)->define[0], 2);
	ft_putstr_fd((*e)->define[3], 2);
	ft_putstr_fd((*e)->define[4], 2);
	ft_putendl_fd((*e)->define[5], 2);
}

void		opt_print_error(char **argv, t_opt **e)
{
	if ((*e)->error == 1)
	{
		ft_putstr_fd((*e)->define[0], 2);
		ft_putendl_fd(": ERROR MALLOC.", 2);
	}
	else if ((*e)->error == 2)
		print_short_error(e);
	else if ((*e)->error == 3)
		print_long_error(argv, e);
}
