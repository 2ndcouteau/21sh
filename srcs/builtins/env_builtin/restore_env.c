/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:49:54 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:51:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	**restore_env(t_env **e, char **save_env)
{
	(*e)->env = ft_free_tab((*e)->env);
	(*e)->env = save_env;
	save_env = NULL;
	return (NULL);
}
