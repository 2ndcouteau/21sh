/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:50:48 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:01:28 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

char		**save_env_fct(t_env **e)
{
	char	**save_env;
	int		size_env;
	int		cpt;

	cpt = 0;
	size_env = ft_tablen((*e)->env);
	if (!(save_env = (char**)malloc(sizeof(char*) * (size_env + 1))))
		exit(EXIT_FAILURE);
	while ((*e)->env[cpt] != NULL)
	{
		save_env[cpt] = ft_strdup((*e)->env[cpt]);
		cpt++;
	}
	save_env[cpt] = NULL;
	return (save_env);
}
