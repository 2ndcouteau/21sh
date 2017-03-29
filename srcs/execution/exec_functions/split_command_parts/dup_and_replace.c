/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:29:43 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:31:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	dup_variable(t_env **e, char *command, int *i, char *new_str)
{
	int a;
	int pos;
	int cpt;
	int len_variable_name;

	a = 0;
	cpt = 0;
	len_variable_name = count_len_variable_name(command + ((*i) + 1));
	if ((pos = env_position_line(e, command + (*i), len_variable_name)) != -1)
	{
		while ((*e)->env[pos][cpt] != '=')
			++cpt;
		++cpt;
		while ((*e)->env[pos][cpt] != '\0')
		{
			new_str[a] = (*e)->env[pos][cpt];
			++a;
			++cpt;
		}
	}
	(*i) += (len_variable_name + 1);
	return (a);
}

static void	copy_char(char *command, char *new_str, int *a, int *i)
{
	if (command[(*i)] == '\\' && command[(*i) + 1] != '\0')
		(*i)++;
	new_str[(*a)] = command[(*i)];
	(*a)++;
	(*i)++;
}

char		*dup_and_replace(t_env **e, char *command, int i, int len_word)
{
	char	mode_quote;
	char	*new_str;
	int		a;

	a = 0;
	mode_quote = MODE_NO_QUOTE;
	if (!(new_str = (char *)malloc(sizeof(char) * (len_word + 1))))
		exit(EXIT_FAILURE);
	while (!ft_isthischar(" \t\n", command[i]) && command[i] != '\0')
		i++;
	while (command[i] != '\0' && (ft_isthischar(" \t\n", command[i]) ||
												mode_quote != MODE_NO_QUOTE))
	{
		if (!check_quote_mode_dup(command, &mode_quote, i))
		{
			if (command[i] == '$' && mode_quote != MODE_SIMPLE_QUOTE)
				a += dup_variable(e, command, &i, (new_str + a));
			else
				copy_char(command, new_str, &a, &i);
		}
		else
			++i;
	}
	new_str[a] = '\0';
	return (new_str);
}
