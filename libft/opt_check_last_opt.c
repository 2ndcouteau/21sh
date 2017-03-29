/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_check_last_opt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 18:30:06 by qrosa             #+#    #+#             */
/*   Updated: 2016/02/19 18:41:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		opt_check_last_opt(char *opt_all, char opt0, char opt1)
{
	int		i;

	i = 0;
	if (opt_all != NULL)
	{
		while (opt_all[i] != '\0')
			i++;
		while (i > 0)
		{
			i--;
			if (opt_all[i] == opt0)
				return (0);
			else if (opt_all[i] == opt1)
				return (1);
		}
	}
	return (-1);
}
