/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:51:05 by kaosu             #+#    #+#             */
/*   Updated: 2017/02/08 02:17:10 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static char	*setenv_new_line(char *var_env, char *value)
{
	int		len_line;
	int		len_word;
	char	*new_line;

	len_word = 0;
	len_line = ft_strlen(var_env) + ft_strlen(value);
	if (!(new_line = (char*)malloc(sizeof(char) * (len_line + 2))))
		exit(EXIT_FAILURE);
	new_line[len_line + 1] = '\0';
	len_line = 0;
	while (var_env[len_word] != '\0')
		new_line[len_line++] = var_env[len_word++];
	new_line[len_line++] = '=';
	len_word = 0;
	while (value[len_word] != '\0')
		new_line[len_line++] = value[len_word++];
	return (new_line);
}

int			setenv_var(t_env **e, char *var_env, char *value)
{
	char	**new;
	int		tab_len;

	tab_len = (*e)->size_env + 2;
	if (!(new = (char**)malloc(sizeof(char*) * tab_len)))
		return (-1);
	tab_len = 0;
	while ((*e)->env[tab_len] != NULL)
	{
		new[tab_len] = ft_strdup((*e)->env[tab_len]);
		tab_len++;
	}
	new[tab_len++] = setenv_new_line(var_env, value);
	(*e)->size_env++;
	new[tab_len] = NULL;
	(*e)->env = ft_free_tab((*e)->env);
	(*e)->env = new;
	new = NULL;
	return (tab_len);
}

void		setenv_new_value(t_env **e)
{
	int		ret;
	int		pos;
	char	*tmp;

	ret = 0;
	tmp = ft_strjoin((*e)->current_cmd->split_line[1], "=");
	if ((*e)->current_cmd->size_split_line == 2)
	{
		if ((pos = env_position_line(e, tmp, ft_strlen(tmp))) >= 0)
			env_replace_var((*e)->env, tmp, "", pos);
		else
			ret = setenv_var(e, (*e)->current_cmd->split_line[1], "");
	}
	else
	{
		if ((pos = env_position_line(e, tmp, ft_strlen(tmp))) >= 0)
			env_replace_var((*e)->env, tmp,
	(*e)->current_cmd->split_line[2], pos);
		else
			ret = setenv_var(e, (*e)->current_cmd->split_line[1],
	(*e)->current_cmd->split_line[2]);
	}
	ft_free_line(&tmp);
	if (ret == -1)
		exit(EXIT_FAILURE);
}

char		setenv_builtin(t_env **e)
{
	if ((*e)->current_cmd->size_split_line == 1)
		env_builtin(e);
	else if (ft_isalpha((*e)->current_cmd->split_line[1][0]) ||\
		(*e)->current_cmd->split_line[1][0] == '_')
	{
		if (ft_isalnum_line((*e)->current_cmd->split_line[1]))
		{
			setenv_new_value(e);
			return (SUCCESS);
		}
		else
			sh_print_error(4, NULL);
	}
	else
		sh_print_error(3, NULL);
	return (ERROR);
}
