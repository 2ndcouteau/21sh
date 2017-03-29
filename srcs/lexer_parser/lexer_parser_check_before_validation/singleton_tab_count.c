/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_tab_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 13:06:52 by qrosa             #+#    #+#             */
/*   Updated: 2016/07/28 14:30:36 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

t_count		*singleton_t_count(t_count *tab_count)
{
	static t_count	*tmp;

	if (tab_count != NULL)
		tmp = tab_count;
	return (tmp);
}
