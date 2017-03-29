/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len_variable_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:43:21 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:24:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

int	count_len_variable_name(char *str)
{
	int	offset;

	offset = 0;
	if (!ft_isthischar(" \t\n", str[offset]) || str[offset] == '\0')
		return (0);
	if (ft_isalpha(str[offset]) || str[offset] == '_')
	{
		++offset;
		while (ft_isalnum_var(str[offset]))
			++offset;
		return (offset);
	}
	return (0);
}
