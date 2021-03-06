/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispace_tab_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 21:54:59 by qrosa             #+#    #+#             */
/*   Updated: 2016/02/23 21:57:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_ispace_tab_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}
