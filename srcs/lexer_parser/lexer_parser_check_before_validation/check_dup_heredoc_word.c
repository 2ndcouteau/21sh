/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_heredoc_word.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 21:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:58:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	len_words(char *command_line, int i)
{
	int		len;
	bool	check;
	int		nb_back_slash;

	len = 0;
	check = 0;
	nb_back_slash = 0;
	while (command_line[i] == ' ' || command_line[i] == '\t')
		i++;
	while ((!ft_isnthischar(";|><\n ", command_line[i]) &&
										command_line[i] != '\0') || check == 1)
	{
		check = 0;
		if (command_line[i] == '\\' && check == 0)
		{
			nb_back_slash += 1;
			check = 1;
		}
		else
			check = 0;
		len++;
		i++;
	}
	i--;
	return (len - nb_back_slash);
}

static void	set_error_heredoc_word(t_count *tab_count, char symbol)
{
	if (tab_count->heredoc_mode >= 0)
	{
		if (symbol == '<')
			tab_count->heredoc_mode = -2;
		else
			tab_count->heredoc_mode = -1;
	}
}

static void	strdup_check_bs(t_count *tab_count, char *command_line, int len,
																		int i)
{
	int		check;
	int		cpt;

	cpt = 0;
	check = 0;
	while (cpt < len)
	{
		if (command_line[i] == '\\' && check == 0)
		{
			i++;
			check = 1;
		}
		else
		{
			check = 0;
			tab_count->last_word_heredoc->word[cpt] = command_line[i];
			i++;
			cpt++;
		}
	}
	tab_count->last_word_heredoc->word[cpt] = '\0';
}

void		dup_heredoc_word(t_count *tab_count, char *command_line, int i)
{
	int		len;

	len = len_words(command_line, i);
	if (!(tab_count->last_word_heredoc->word =
									(char *)malloc(sizeof(char) * (len + 1))))
		exit(EXIT_FAILURE);
	while (command_line[i] == ' ' || command_line[i] == '\t')
		i++;
	if (command_line[i] == '\0' || !ft_isthischar(";\n<>|", command_line[i]) ||
													!is_cmdand(command_line, i))
		set_error_heredoc_word(tab_count, command_line[i]);
	strdup_check_bs(tab_count, command_line, len, i);
}
