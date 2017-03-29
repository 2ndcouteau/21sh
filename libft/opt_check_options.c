/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_check_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:09:14 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:38:46 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The bool check is True if option has short AND long writing.
*/

static	bool	check_short(t_opt **e, char opt, bool check)
{
	if (ft_strchr((*e)->opt, opt))
		return (1);
	else if (check == 1)
		return (1);
	else
		return (0);
}

static	bool	check_long(t_opt **e, char *opt, bool check)
{
	if (ft_strstr((*e)->l_opt, opt))
		return (1);
	else if (check == 1)
		return (1);
	else
		return (0);
}

/*
** Call "check_short" || "check long" once more for each new option.
*/

static	void	check_short_option(t_opt **e)
{
	(*e)->opt_b->a = check_short(e, 'a', (*e)->opt_b->a);
}

static	void	check_long_option(t_opt **e)
{
	(*e)->opt_b->a = check_long(e, "all", (*e)->opt_b->a);
}

void			opt_check_options(t_opt **e)
{
	if ((*e)->opt != NULL)
		check_short_option(e);
	if ((*e)->l_opt != NULL)
		check_long_option(e);
}
