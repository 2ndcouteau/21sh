/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_replace_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:28:12 by kaosu             #+#    #+#             */
/*   Updated: 2016/03/02 18:10:12 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	env_replace_var(char **env, char *variable, char *value, int position)
{
	env[position] = ft_free_line(&env[position]);
	env[position] = ft_strjoin(variable, value);
}
