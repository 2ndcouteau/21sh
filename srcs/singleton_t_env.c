/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_t_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 14:18:59 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:56:03 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

t_env	*singleton_t_env(t_env *env)
{
	static t_env	*tmp;

	if (env != NULL)
		tmp = env;
	return (tmp);
}