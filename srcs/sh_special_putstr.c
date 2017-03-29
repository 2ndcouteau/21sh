/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_special_putstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 01:03:37 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 17:55:43 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	sh_special_putstr(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(str);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			tmp[i] = ' ';
		i++;
	}
	ft_putstr(tmp);
	tmp = ft_free_line(&tmp);
}
