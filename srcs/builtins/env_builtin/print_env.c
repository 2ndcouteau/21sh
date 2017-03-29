/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:49:19 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:51:11 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	print_env(t_env **e)
{
	int	cpt;

	cpt = 0;
	while ((*e)->env[cpt] != NULL)
		ft_putendl((*e)->env[cpt++]);
}
