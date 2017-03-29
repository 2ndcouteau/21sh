/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free_all_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 00:25:11 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:02:10 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		env_free_cmd(t_env **e)
{
	if ((*e)->current_cmd != NULL)
	{
		if ((*e)->current_cmd->line != NULL)
			(*e)->current_cmd->line = ft_free_line(&((*e)->current_cmd->line));
		(*e)->current_cmd->split_line =
									ft_free_tab((*e)->current_cmd->split_line);
		if ((*e)->current_cmd->error_name != NULL)
			(*e)->current_cmd->error_name =
								ft_free_line(&((*e)->current_cmd->error_name));
		free((*e)->current_cmd);
		(*e)->current_cmd = NULL;
	}
}

static void	node_free_historical(t_hist *tmp)
{
	if (tmp != NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		if (tmp->command_line != NULL)
			tmp->command_line = ft_free_line(&(tmp->command_line));
		free(tmp);
		tmp = NULL;
	}
}

static void	free_all_historical(t_env **e)
{
	t_hist	*tmp;

	if ((*e)->historical != NULL)
	{
		while ((*e)->historical->next != NULL)
		{
			tmp = (*e)->historical->next;
			node_free_historical((*e)->historical);
			(*e)->historical = tmp;
		}
		node_free_historical((*e)->historical);
	}
}

void		env_free_all_env(t_env **e)
{
	if (*e != NULL)
	{
		free_all_historical(e);
		free_cmd_struct(e);
		free_posicao_struct(e);
		free_tab_count(e);
		(*e)->current_cmd = NULL;
		(*e)->env = ft_free_tab((*e)->env);
		(*e)->env = NULL;
		(*e)->original_env = ft_free_tab((*e)->original_env);
		(*e)->original_env = NULL;
		free(*e);
		*e = NULL;
	}
}
