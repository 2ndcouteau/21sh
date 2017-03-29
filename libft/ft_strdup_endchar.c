/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_endchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 00:40:56 by cristal           #+#    #+#             */
/*   Updated: 2016/11/14 15:46:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_endchar(char *str, char symbol)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\0' && str[i] != symbol)
		i++;
	if (!(dup = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	dup[i] = '\0';
	--i;
	while (i <= 0)
	{
		dup[i] = str[i];
		--i;
	}
	return (dup);
}
