/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nb_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:27:47 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:26:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int		check_quote_mode_count_words(char sign, int mode)
{
	if (mode == MODE_NO_QUOTE)
	{
		if (sign == '\"')
			return (MODE_DOUBLE_QUOTE);
		else if (sign == '\'')
			return (MODE_SIMPLE_QUOTE);
		else if (sign == '`')
			return (MODE_BACK_QUOTE);
	}
	else
	{
		if (mode == MODE_SIMPLE_QUOTE && sign == '\'')
			return (MODE_NO_QUOTE);
		else if (mode == MODE_DOUBLE_QUOTE && sign == '\"')
			return (MODE_NO_QUOTE);
		else if (mode == MODE_DOUBLE_QUOTE && sign == '`')
			return (MODE_BACK_DOUBLE_QUOTE);
		else if (mode == MODE_BACK_QUOTE && sign == '`')
			return (MODE_NO_QUOTE);
		else if (mode == MODE_BACK_DOUBLE_QUOTE && sign == '`')
			return (MODE_DOUBLE_QUOTE);
	}
	return (mode);
}

static char		check_back_slash_echap_jump_count_nbr_words(char *command,
																		int i)
{
	if (command[i] == '\\')
	{
		if (command[i + 1] != '\0')
			return (0);
	}
	return (1);
}

int				count_nb_words(char *command)
{
	int i;
	int nbr_words;
	int mode_quote;

	i = 0;
	nbr_words = 0;
	mode_quote = MODE_NO_QUOTE;
	while (command[i] != '\0')
	{
		while (!ft_isthischar(" \t\n", command[i]) &&
													mode_quote == MODE_NO_QUOTE)
			i++;
		while ((ft_isthischar(" \t\n", command[i]) ||
							mode_quote != MODE_NO_QUOTE) && command[i] != '\0')
		{
			if (check_back_slash_echap_jump_count_nbr_words(command, i))
				mode_quote =
						check_quote_mode_count_words(command[i], mode_quote);
			else
				++i;
			i++;
		}
		++nbr_words;
	}
	return (nbr_words);
}
