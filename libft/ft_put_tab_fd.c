/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tab_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:45:08 by qrosa             #+#    #+#             */
/*   Updated: 2016/04/03 22:35:48 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_tab_fd(char **mytab, int fd)
{
	int		cpt;

	cpt = 0;
	while (mytab[cpt] != NULL)
		ft_putendl_fd(mytab[cpt++], fd);
}
