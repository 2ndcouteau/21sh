/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_suppr_double_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 19:01:49 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:36:24 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	add_quote(char *double_char, char symbol)
{
	if (symbol == '\'')
		double_char[0] = '\0';
}

static void	add_double_quote(char *double_char, char symbol)
{
	if (symbol == '\"')
		double_char[0] = '\0';
	else if (symbol == '`')
	{
		if (double_char[1] != '`')
			double_char[1] = '`';
		else
			double_char[1] = '\0';
	}
}

static void	add_back_quote(char *double_char, char symbol)
{
	if (symbol == '`')
		double_char[0] = '\0';
}

void		add_suppr_double_char(char *double_char, char *command_line,
																	int start)
{
	if (!check_back_slash(command_line, start))
	{
		if (double_char[0] == '\0')
			double_char[0] = command_line[start];
		else if (double_char[0] == '\'')
			add_quote(double_char, command_line[start]);
		else if (double_char[0] == '`')
			add_back_quote(double_char, command_line[start]);
		else
			add_double_quote(double_char, command_line[start]);
	}
}
