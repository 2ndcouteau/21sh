/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_trimndup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:54:33 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 18:01:38 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_trimndup(const char *str, size_t start, size_t len)
{
	int i;

	i = 0;
	while (str[start + i] == ' ' || str[start + i] == '\t' ||
														str[start + i] == '\n')
		i++;
	start += i;
	len -= (i + 1);
	while ((str[start + len] == ' ' || str[start + len] == '\t' ||
										str[start + len] == '\n') && len > 0)
		len -= 1;
	len += 1;
	if (len > 0)
		return (ft_strndup(str, start, len));
	return (NULL);
}
