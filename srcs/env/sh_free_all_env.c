/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_free_all_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:40:20 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 13:49:40 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	sh_node_free_historical(t_hist *tmp)
{
	if (tmp != NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		if (tmp->command_line != NULL)
			ft_free_line(&(tmp->command_line));
		free(tmp);
		tmp = NULL;
	}
}

void	sh_free_historical(t_env **e)
{
	t_hist	*tmp;

	if ((*e)->historical != NULL)
	{
		while ((*e)->historical->next != NULL)
		{
			tmp = (*e)->historical->next;
			sh_node_free_historical((*e)->historical);
			(*e)->historical = tmp;
		}
		sh_node_free_historical((*e)->historical);
	}
}

void	free_all_env(t_env **e)
{
	if (*e != NULL)
	{
		sh_free_historical(e);
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
