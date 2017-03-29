/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_clean_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 16:10:58 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:27:29 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	split_replace_and_dup(t_env **e, char **tab_words, char *command,
																int nbr_words)
{
	int		count_word;
	int		len_word;
	int		offset_cmd;
	int		i;

	i = 0;
	count_word = 0;
	while (count_word < nbr_words && command[i] != '\0')
	{
		offset_cmd = 0;
		len_word = count_word_len(e, command, i, &offset_cmd);
		if (len_word > 0)
		{
			tab_words[count_word] = dup_and_replace(e, command, i, len_word);
			++count_word;
		}
		i += offset_cmd;
	}
	tab_words[count_word] = NULL;
}

char		**split_clean_command(t_env **e, char *command)
{
	int		nbr_words;
	char	**tab_words;

	if (command == NULL)
		return (NULL);
	nbr_words = count_nb_words(command);
	if (!(tab_words = (char **)malloc(sizeof(char*) * (nbr_words + 1))))
		exit(EXIT_FAILURE);
	tab_words[nbr_words] = NULL;
	split_replace_and_dup(e, tab_words, command, nbr_words);
	return (tab_words);
}
