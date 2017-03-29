/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote_mode_dup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:04:05 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 11:04:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	check_simple_quote_mode_dup(char *mode_quote)
{
	if (*mode_quote == MODE_NO_QUOTE)
		*mode_quote = MODE_SIMPLE_QUOTE;
	else
		*mode_quote = MODE_NO_QUOTE;
	return (1);
}

static int	check_double_quote_mode_dup(char *mode_quote)
{
	if (*mode_quote == MODE_NO_QUOTE)
		*mode_quote = MODE_DOUBLE_QUOTE;
	else
		*mode_quote = MODE_NO_QUOTE;
	return (1);
}

static int	check_back_quote_mode_dup(char *mode_quote)
{
	if (*mode_quote == MODE_NO_QUOTE)
		*mode_quote = MODE_BACK_QUOTE;
	else if (*mode_quote == MODE_DOUBLE_QUOTE)
		*mode_quote = MODE_BACK_DOUBLE_QUOTE;
	else if (*mode_quote == MODE_BACK_DOUBLE_QUOTE)
		*mode_quote = MODE_DOUBLE_QUOTE;
	else
		*mode_quote = MODE_NO_QUOTE;
	return (1);
}

int			check_quote_mode_dup(char *command, char *mode_quote, int i)
{
	if (command[i] == '\'' && *mode_quote != MODE_DOUBLE_QUOTE && *mode_quote !=
					MODE_BACK_QUOTE && *mode_quote != MODE_BACK_DOUBLE_QUOTE)
		return (check_simple_quote_mode_dup(mode_quote));
	else if (command[i] == '\"' && *mode_quote != MODE_SIMPLE_QUOTE &&
		*mode_quote != MODE_BACK_QUOTE && *mode_quote != MODE_BACK_DOUBLE_QUOTE)
		return (check_double_quote_mode_dup(mode_quote));
	else if (command[i] == '`' && *mode_quote != MODE_SIMPLE_QUOTE)
		return (check_back_quote_mode_dup(mode_quote));
	return (0);
}
