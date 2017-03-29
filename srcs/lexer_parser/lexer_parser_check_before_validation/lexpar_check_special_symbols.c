/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexpar_check_special_symbols.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:04:05 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:06:04 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static const char	g_tab_special_symbol[NB_SPECIAL_SYMBOL] = {
	'\'',
	'`',
	'\"',
	';',
	'>',
	'|',
};

int					(*g_check_previous_symbols[NB_SPECIAL_SYMBOL])
														(t_count *tab_count) =
{
	check_quote,
	check_back_quote,
	check_double_quote,
	check_semi_colon,
	check_major,
	check_pipe,
};

int					check_special_symbols(char symbol)
{
	int	i;

	i = 0;
	while (i < NB_SPECIAL_SYMBOL)
	{
		if (symbol == g_tab_special_symbol[i])
			return (i);
		i++;
	}
	return (-1);
}
