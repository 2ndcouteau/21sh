/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_list_push_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:40:12 by qrosa             #+#    #+#             */
/*   Updated: 2016/11/22 16:41:50 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void		free_hist_last_elem(t_hist *hist)
{
	hist->prev->next = NULL;
	hist->prev = NULL;
	ft_free_line(&(hist->command_line));
	free(hist);
	hist = NULL;
}

static	void	free_last_elem(t_hist *hist)
{
	while (hist->index != 0)
	{
		hist->index -= 1;
		hist = hist->next;
	}
	free_hist_last_elem(hist);
}

void			hist_list_push_front_max(t_env **e)
{
	hist_list_push_front_struct(e);
	free_last_elem((*e)->historical);
}

void			hist_list_push_front_struct(t_env **e)
{
	t_hist	*tmp;

	if ((*e)->historical != NULL)
	{
		if (!(tmp = (t_hist *)malloc(sizeof(t_hist))))
			exit(EXIT_FAILURE);
		tmp->command_line = ft_strdup((*e)->command_line);
		tmp->index = (*e)->historical->index + 1;
		tmp->next = (*e)->historical;
		(*e)->historical->prev = tmp;
		(*e)->historical = tmp;
		(*e)->historical->prev = NULL;
		tmp = NULL;
	}
}
