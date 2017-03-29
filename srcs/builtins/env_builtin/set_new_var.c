/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:46:53 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:54:19 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	set_var_in_env(t_env **e, char *name_var, char *value_var)
{
	int		ret;
	int		pos;
	char	*tmp;

	ret = 0;
	tmp = ft_strjoin(name_var, "=");
	if ((pos = env_position_line(e, tmp, ft_strlen(tmp))) >= 0)
		env_replace_var((*e)->env, tmp, value_var, pos);
	else
		ret = setenv_var(e, name_var, value_var);
	ft_free_line(&tmp);
	if (ret == -1)
		exit(EXIT_FAILURE);
}

void		set_new_var(t_env **e, int ret, int cpt)
{
	int		len;
	char	*name_var;
	char	*value_var;
	int		nb_new_var;

	nb_new_var = cpt;
	while (cpt < (nb_new_var + ret))
	{
		len = 0;
		while ((*e)->current_cmd->split_line[cpt][len] != '=')
			++len;
		name_var = ft_strndup((*e)->current_cmd->split_line[cpt], 0, len);
		++len;
		value_var = ft_strdup((*e)->current_cmd->split_line[cpt] + len);
		if (name_var != NULL && *name_var != '\0' && value_var != NULL)
			set_var_in_env(e, name_var, value_var);
		name_var = ft_free_line(&name_var);
		value_var = ft_free_line(&value_var);
		++cpt;
	}
}
