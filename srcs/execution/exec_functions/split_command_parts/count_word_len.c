/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:31:21 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 10:58:35 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	check_if_variable_call(t_env **e, char *str, int *offset_cmd,
	int *len_total)
{
	int		pos;
	int		i;
	int		offset_var;

	i = 0;
	offset_var = 0;
	if (str[i] == '$')
	{
		offset_var = count_len_variable_name(str + (i + 1));
		if (offset_var > 0)
		{
			if ((pos = env_position_line(e, str + i, offset_var)) != -1)
				(*len_total) += ft_strlen((*e)->env[pos]) - (offset_var - 1);
			i += offset_var;
		}
		--(*len_total);
	}
	(*offset_cmd) += offset_var;
	return (i);
}

static int	check_back_slash_echap_jump(char *str, int *i, int *offset_cmd)
{
	if (str[(*i)] == '\\')
	{
		if (str[(*i) + 1] != '\0')
		{
			++(*offset_cmd);
			++(*i);
		}
		return (0);
	}
	return (1);
}

static void	browse_line_count(int *i, int *empty_offset)
{
	++*empty_offset;
	++*i;
}

int			count_word_len(t_env **e, char *str, int i, int *offset_cmd)
{
	int		len_word;
	int		empty_offset;
	char	mode_quote;

	len_word = 0;
	empty_offset = 0;
	mode_quote = MODE_NO_QUOTE;
	while (!ft_isthischar(" \t\n", str[i]) && str[i] != '\0')
		browse_line_count(&empty_offset, &i);
	while ((ft_isthischar(" \t\n", str[i]) || mode_quote != MODE_NO_QUOTE) &&
																str[i] != '\0')
	{
		if (check_back_slash_echap_jump(str, &i, offset_cmd))
		{
			if (mode_quote != MODE_SIMPLE_QUOTE)
				i += check_if_variable_call(e, (str + i), offset_cmd,
																	&len_word);
			len_word = check_quote_mode(str, i, &mode_quote, len_word);
		}
		++len_word;
		++(*offset_cmd);
		++i;
	}
	(*offset_cmd) += empty_offset;
	return (len_word);
}
