/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:00:18 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/03 02:22:42 by kaosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	int		a;
	int		len;

	a = 0;
	len = ft_strlen(str) + 1;
	if (!(result = ft_memalloc(len)))
		return (NULL);
	while (str[a] != '\0')
	{
		result[a] = str[a];
		a++;
	}
	result[a] = '\0';
	return (result);
}
