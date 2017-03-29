/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexpar_check_special_double_symbols.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:05:11 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:05:15 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static const char	g_tab_special_double_symbol[NB_SPECIAL_DOUBLE_SYMBOL] = {
	'(',
	')',
	'{',
	'}',
	'[',
	']'
};

int					(*g_check_previous_double_symbols[NB_SPECIAL_DOUBLE_SYMBOL])
														(t_count *tab_count) =
{
	check_open_parenthese,
	check_close_parenthese,
	check_open_brace,
	check_close_brace,
	check_open_bracket,
	check_close_bracket
};

int					check_special_double_symbols(char symbol)
{
	int	i;

	i = 0;
	while (i < NB_SPECIAL_DOUBLE_SYMBOL)
	{
		if (symbol == g_tab_special_double_symbol[i])
			return (i);
		i++;
	}
	return (-1);
}
