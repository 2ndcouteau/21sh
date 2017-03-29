/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:51:29 by qrosa             #+#    #+#             */
/*   Updated: 2016/06/01 11:54:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnendl(char const *str, int n)
{
	int	len;

	if (str != NULL)
	{
		len = ft_strlen(str);
		if (n <= len)
			write(1, str, n);
		write(1, "\n", 1);
	}
}
