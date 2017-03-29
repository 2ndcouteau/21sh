/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_echap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:20:02 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 13:20:21 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

bool	echap(t_env **e, char **new_tmp)
{
	t_position	*posicao;

	posicao = (*e)->posicao;
	if (posicao && new_tmp)
		posicao = NULL;
	return (SUCCESS);
}
