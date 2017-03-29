/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_add_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:38:46 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 18:01:15 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	"len" argument is the max len of Buffer "str"
*/

bool	ft_buff_add_char(char *str, char add, int len)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	if (add == 0 || (a + 1) >= len)
		return (1);
	str[a] = add;
	str[a + 1] = '\0';
	return (0);
}
