/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_trimndup_echap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:54:33 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 18:02:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	test_echap_char(const char *str, int start, int len)
{
	int a;

	a = 0;
	if (str[start + len] == '\\' && str[start + len + 1] != '\0')
	{
		while (str[start + len - a] == '\\' && (a < (start + len)))
			++a;
		if (a % 2 == 1)
			return (2);
	}
	return (1);
}

char		*ft_str_trimndup_echap(const char *str, size_t start, size_t len)
{
	int i;

	i = 0;
	while (str[start + i] == ' ' || str[start + i] == '\t' ||
														str[start + i] == '\n')
		++i;
	start += i;
	len -= (i + 1);
	while ((str[start + len] == ' ' || str[start + len] == '\t' ||
										str[start + len] == '\n') && len > 0)
		len -= 1;
	len += test_echap_char(str, start, len);
	if (len > 0)
		return (ft_strndup(str, start, len));
	return (NULL);
}
