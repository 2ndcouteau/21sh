/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:17:56 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 23:38:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_lenjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (s1[a] != '\0')
		a++;
	while (s2[b] != '\0')
		b++;
	a += b;
	return (a);
}

static void	ft_strcpjoin(char const *s1, char const *s2, char *dst)
{
	size_t	a;
	size_t	i;

	i = 0;
	a = 0;
	while (s1[a] != '\0')
	{
		dst[i] = s1[a];
		a++;
		i++;
	}
	a = 0;
	while (s2[a] != '\0')
	{
		dst[i] = s2[a];
		a++;
		i++;
	}
	dst[i] = '\0';
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len_total;

	result = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		len_total = ft_lenjoin(s1, s2) + 1;
		result = ft_memalloc(len_total);
		if (result == NULL)
			return (NULL);
		ft_strcpjoin(s1, s2, result);
		return (result);
	}
	else if (s1 != NULL)
		return (ft_strdup(s1));
	else if (s2 != NULL)
		return (ft_strdup(s2));
	else
		return (NULL);
}
