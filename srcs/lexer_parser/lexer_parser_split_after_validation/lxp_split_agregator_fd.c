/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_split_agregator_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 21:15:29 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/11 17:45:25 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static char	*set_ambigous_redirection(t_env **e, char *command_line,
													int pos_line, int pos_word)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while (command_line[pos_line + pos_word + a] != '>')
		a++;
	a += 2;
	while (ft_isalnum(command_line[pos_line + pos_word + a + i]))
		i++;
	(*e)->current_cmd->error_name = ft_strndup(command_line,
											(pos_line + pos_word + a), (i + 1));
	(*e)->current_cmd->error_nbr = -3;
	return (ft_strdup("\0"));
}

static int	check_moove_count_i(char *command_line, int pos_line, int pos_word,
																		int a)
{
	int i;

	i = 0;
	if (command_line[pos_line + pos_word + a + i] == '-')
	{
		if (!ft_isthischar(" \t\n;|",
							command_line[pos_line + pos_word + a + i + 1]) ||
						command_line[pos_line + pos_word + a + i + 1] == '\0')
			return (1);
	}
	while (ft_isdigit(command_line[pos_line + pos_word + a + i]))
		i++;
	return (i);
}

static int	check_moove_count_a(char *command_line, int pos_line, int pos_word)
{
	int a;

	a = 0;
	while (command_line[pos_line + pos_word + a] != '>')
		a++;
	return (a);
}

char		*split_agregator_fd(t_env **e, char *command_line, int pos_line,
																int pos_word)
{
	int i;
	int a;

	(*e)->current_cmd->value_token = VALUE_TOKEN_AGREG_FD;
	a = 2 + check_moove_count_a(command_line, pos_line, pos_word);
	if ((i = check_moove_count_i(command_line, pos_line, pos_word, a)) == 0)
	{
		while (command_line[pos_line + pos_word + a + i] == ' ')
			i++;
		if (command_line[pos_line + pos_word + a + i] == '<' ||
							command_line[pos_line + pos_word + a + i] == '>')
			return (set_ambigous_redirection(e, command_line, pos_line,
																	pos_word));
	}
	if (!ft_isthischar(" \t\n;|", command_line[pos_line + pos_word + a + i]) ||
							command_line[pos_line + pos_word + a + i] == '\0')
		return (ft_strndup(command_line, (pos_line + pos_word), (a + i)));
	else if (command_line[pos_line + pos_word + a + i] == '>' ||
							command_line[pos_line + pos_word + a + i] == '<')
		return (ft_strndup(command_line, (pos_line + pos_word), (a + i)));
	else if (command_line[pos_line + pos_word + a + i] == '#')
		return (set_ambigous_redirection(e, command_line, pos_line, pos_word));
	else
		return (ft_strndup(command_line, (pos_line + pos_word), a));
}
