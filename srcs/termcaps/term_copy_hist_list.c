/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_copy_hist_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:18:04 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 15:13:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		free_copy_hist_list(t_env **e)
{
	t_c_hist	*tmp;

	tmp = (*e)->posicao->copy_hist_begin;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		if ((*e)->posicao->copy_hist_begin != NULL)
			free((*e)->posicao->copy_hist_begin);
		(*e)->posicao->copy_hist_begin = tmp;
	}
	(*e)->posicao->copy_hist_begin = NULL;
}

static void	init_new_copy_hist(t_env **e)
{
	if (!((*e)->posicao->copy_hist_begin = (t_c_hist*)malloc(sizeof(t_c_hist))))
		exit(EXIT_FAILURE);
	(*e)->posicao->copy_hist_begin->index = (*e)->historical->index;
	ft_bzero((*e)->posicao->copy_hist_begin->line, MAX_LEN_COMMAND);
	ft_strcpy((*e)->posicao->copy_hist_begin->line,
												(*e)->historical->command_line);
	(*e)->posicao->copy_hist_begin->next = NULL;
	(*e)->posicao->copy_hist_begin->prev = NULL;
}

static void	new_copy_hist(t_env **e, t_hist *tmp)
{
	t_c_hist	*new;

	new = (*e)->posicao->copy_hist_begin;
	while (new->next != NULL)
		new = new->next;
	if (!(new->next = (t_c_hist*)malloc(sizeof(t_c_hist))))
		exit(EXIT_FAILURE);
	new->next->index = tmp->index;
	ft_bzero(new->next->line, MAX_LEN_COMMAND);
	ft_strcpy(new->next->line, tmp->command_line);
	new->next->next = NULL;
	new->next->prev = new;
	new = new->next;
}

void		term_copy_hist_list(t_env **e)
{
	t_hist		*tmp;

	tmp = (*e)->historical;
	while (tmp != NULL)
	{
		if ((*e)->posicao->copy_hist_begin == NULL)
			init_new_copy_hist(e);
		else
			new_copy_hist(e, tmp);
		tmp = tmp->next;
	}
	tmp = NULL;
}
