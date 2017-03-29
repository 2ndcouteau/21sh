/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnthischar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:52:35 by qrosa             #+#    #+#             */
/*   Updated: 2016/10/07 15:54:20 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isnthischar(char *check_symbol, char symbol)
{
	int i;

	i = 0;
	while (check_symbol[i] != '\0')
	{
		if (check_symbol[i] == symbol)
			return (1);
		i++;
	}
	return (0);
}
