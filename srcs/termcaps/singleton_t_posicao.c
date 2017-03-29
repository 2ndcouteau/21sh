/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_t_posicao.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 11:13:31 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:57:10 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

t_position	*singleton_t_posicao(t_position *posicao)
{
	static t_position	*tmp;

	if (posicao != NULL)
		tmp = posicao;
	return (tmp);
}
