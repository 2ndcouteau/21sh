/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_envreset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:52:27 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:18:28 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char	envreset_builtin(t_env **e)
{
	int	len;

	(*e)->env = ft_free_tab((*e)->env);
	len = ft_tablen((*e)->original_env);
	if (!((*e)->env = (char**)malloc(sizeof(char*) * (len + 1))))
		exit(EXIT_FAILURE);
	len = 0;
	while ((*e)->original_env[len] != NULL)
	{
		(*e)->env[len] = ft_strdup((*e)->original_env[len]);
		len++;
	}
	(*e)->env[len] = NULL;
	return (SUCCESS);
}
