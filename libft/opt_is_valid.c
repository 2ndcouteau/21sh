/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/02/23 19:55:55 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	opt_long_check(char *str, char *opt, t_opt **e, int a)
{
	int		i;

	i = 2;
	while (opt[a] != '\0')
	{
		i = 2;
		while (str[i] != '\0' && opt[a] != '\0' && str[i] == opt[a])
		{
			i++;
			a++;
		}
		if (str[i] == '\0' && (opt[a] == '\0' || opt[a] == ' '))
			return (1);
		while (opt[a] != '\0' && opt[a] != ' ')
			a++;
		if (opt != '\0')
			a++;
	}
	(*e)->error = 3;
	return (0);
}

static bool	opt_check(char *str, char *opt, t_opt **e, int a)
{
	bool	mark;
	int		i;

	mark = 0;
	i = 1;
	while (str[i] != '\0')
	{
		while (mark == 0 && opt[a] != '\0')
		{
			if (str[i] == opt[a])
				mark = 1;
			a++;
		}
		if (mark == 0)
		{
			(*e)->error = 2;
			(*e)->bad_char = str[i];
			return (0);
		}
		mark = 0;
		a = 0;
		i++;
	}
	return (1);
}

static bool	check_mark(t_opt **e)
{
	if ((*e)->mark == 1)
		(*e)->mark = 4;
	else
		(*e)->mark = 3;
	return (1);
}

bool		opt_is_valid(char *str, t_opt **e)
{
	if (str[1] != '-')
	{
		if (opt_check(str, (*e)->define[1], e, 0))
			return (1);
		return (0);
	}
	else
	{
		if (str[2] == '\0')
			return (check_mark(e));
		else
		{
			if (opt_long_check(str, (*e)->define[2], e, 0))
				return (1);
			return (0);
		}
	}
}
