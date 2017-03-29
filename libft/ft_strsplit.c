/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:04:06 by qrosa             #+#    #+#             */
/*   Updated: 2016/02/27 20:10:10 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool		check_arg(char const *str, char sign)
{
	if (str != NULL && sign != 0)
		return (0);
	return (1);
}

static size_t	count_nb_words(char const *str, const char chars)
{
	int		len;
	size_t	nb_words;

	len = 0;
	nb_words = 0;
	while (str[len] != '\0')
	{
		while ((str[len] == chars) && (str[len] != '\0'))
			len++;
		if (str[len] != '\0')
		{
			while ((str[len] != chars) && (str[len] != '\0'))
				len++;
			nb_words++;
		}
	}
	return (nb_words);
}

static void		split_and_copy(char const *str, char **result, size_t nb_words,
	const char chars)
{
	size_t	pos;
	size_t	len_str;
	size_t	len_words;

	pos = 0;
	len_str = 0;
	len_words = 0;
	while ((pos < nb_words) && (str[len_str] != '\0'))
	{
		while ((str[len_str] == chars) && (str[len_str] != '\0'))
			len_str++;
		if (str[len_str] != '\0')
		{
			while ((str[len_str] != chars) && (str[len_str] != '\0'))
			{
				len_str++;
				len_words++;
			}
			result[pos] = ft_strndup(str, (len_str - len_words), len_words);
			pos++;
			len_words = 0;
		}
	}
}

char			**ft_strsplit(char const *str, char chars)
{
	size_t	nb_words;
	char	**result;

	if (check_arg(str, chars))
		return (NULL);
	nb_words = count_nb_words(str, chars);
	if (!(result = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	result[nb_words] = NULL;
	split_and_copy(str, result, nb_words, chars);
	return (result);
}
