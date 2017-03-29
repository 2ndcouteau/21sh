/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:50:21 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:24:57 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	check_simple_quote_mode(char *mode, int len_total)
{
	if (*mode == MODE_NO_QUOTE)
		*mode = MODE_SIMPLE_QUOTE;
	else
		*mode = MODE_NO_QUOTE;
	return (len_total - 1);
}

static int	check_double_quote_mode(char *mode, int len_total)
{
	if (*mode == MODE_NO_QUOTE)
		*mode = MODE_DOUBLE_QUOTE;
	else
		*mode = MODE_NO_QUOTE;
	return (len_total - 1);
}

static int	check_back_quote_mode(char *mode, int len_total)
{
	if (*mode == MODE_NO_QUOTE)
		*mode = MODE_BACK_QUOTE;
	else if (*mode == MODE_DOUBLE_QUOTE)
		*mode = MODE_BACK_DOUBLE_QUOTE;
	else if (*mode == MODE_BACK_DOUBLE_QUOTE)
		*mode = MODE_DOUBLE_QUOTE;
	else
		*mode = MODE_NO_QUOTE;
	return (len_total - 1);
}

int			check_quote_mode(char *str, int i, char *mode, int len_total)
{
	if (str[i] == '\'' && *mode != MODE_DOUBLE_QUOTE && *mode !=
	MODE_BACK_QUOTE && *mode != MODE_BACK_DOUBLE_QUOTE)
		return (check_simple_quote_mode(mode, len_total));
	else if (str[i] == '\"' && *mode != MODE_SIMPLE_QUOTE && *mode !=
	MODE_BACK_QUOTE && *mode != MODE_BACK_DOUBLE_QUOTE)
		return (check_double_quote_mode(mode, len_total));
	else if (str[i] == '`' && *mode != MODE_SIMPLE_QUOTE)
		return (check_back_quote_mode(mode, len_total));
	return (len_total);
}
