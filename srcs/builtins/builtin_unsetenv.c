/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:27:02 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:28:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static bool		var_unsetenv_del(t_env **e, int i)
{
	char	**new;
	int		len;
	int		pos;

	pos = 0;
	len = (*e)->size_env;
	if (!(new = (char**)malloc(sizeof(char*) * len)))
		exit(EXIT_FAILURE);
	len = 0;
	while ((*e)->env[len] != NULL)
	{
		if (len != i)
			new[pos++] = ft_strdup((*e)->env[len++]);
		else
			len++;
	}
	(*e)->size_env--;
	new[pos] = NULL;
	(*e)->env = ft_free_tab((*e)->env);
	(*e)->env = new;
	new = NULL;
	return (SUCCESS);
}

char			unsetenv_builtin(t_env **e)
{
	int		position;
	char	*tmp;

	if (ft_isalnum_line((*e)->current_cmd->split_line[1]))
	{
		tmp = ft_strjoin((*e)->current_cmd->split_line[1], "=");
		if ((position = env_position_line(e, tmp, ft_strlen(tmp))) >= 0)
		{
			free(tmp);
			if (var_unsetenv_del(e, position))
				return (ERROR);
			else
				return (SUCCESS);
		}
		free(tmp);
	}
	return (ERROR);
}
