/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isthischar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 17:03:34 by qrosa             #+#    #+#             */
/*   Updated: 2016/10/04 17:05:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isthischar(char *check_symbol, char symbol)
{
	int i;

	i = 0;
	while (check_symbol[i] != '\0')
	{
		if (check_symbol[i] == symbol)
			return (0);
		i++;
	}
	return (1);
}
