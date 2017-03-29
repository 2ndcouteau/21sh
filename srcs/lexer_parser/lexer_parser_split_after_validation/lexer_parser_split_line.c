/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser_split_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 21:06:55 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:49:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	replace_cut_node(char *command_line, int pos_line, int pos_word)
{
	int		i;

	i = 1;
	while (i < pos_word)
	{
		if (ft_isdigit(command_line[pos_line + pos_word - i]))
			i++;
		else if (command_line[pos_line + pos_word - i] == ' ' ||
								command_line[pos_line + pos_word - i] == '\n' ||
								command_line[pos_line + pos_word - i] == '\t')
			return (i - 1);
		else
			return (0);
	}
	if (command_line[pos_line + pos_word - i] == ' ' ||
								command_line[pos_line + pos_word - i] == '\n' ||
								command_line[pos_line + pos_word - i] == '\t')
		return (i - 1);
	return (i);
}

static void	check_heredoc(char *command_line, int start, int ret,
															int *heredoc_mode)
{
	*heredoc_mode = NO_HEREDOC;
	if (ret == 2)
	{
		if (command_line[start + ret - 1] == '<' &&
										command_line[start + ret - 2] == '<')
			*heredoc_mode = HEREDOC_ACTIVE;
	}
}

static bool	norm_condition(char *command_line, int pos_line, int pos_word)
{
	if (command_line[pos_line + pos_word] == '>' &&
								command_line[pos_line + pos_word + 1] == '&')
		return (SUCCESS);
	return (ERROR);
}

void		lexer_parser_split_line_in_list(t_env **e, char *command_line)
{
	int		pos_line;
	int		pos_word;
	int		ret;
	int		heredoc_mode;

	pos_line = 0;
	pos_word = 0;
	heredoc_mode = NO_HEREDOC;
	while (command_line[pos_line] != '\0')
	{
		ft_bzero((*e)->current_cmd->double_char, 3);
		while (is_special_split_char(command_line, (pos_line + pos_word),
											(*e)->current_cmd, &heredoc_mode))
			pos_word++;
		if (!norm_condition(command_line, pos_line, pos_word))
			pos_word -= replace_cut_node(command_line, pos_line, pos_word);
		if (!check_empty_command_node(command_line, pos_line, pos_word))
			create_command_node(e, command_line, pos_line, pos_word);
		if ((ret = create_special_char_node(e, command_line, pos_line,
															pos_word)) == -1)
			break ;
		check_heredoc(command_line, (pos_line + pos_word), ret, &heredoc_mode);
		pos_line += pos_word + ret;
		pos_word = 0;
	}
}
