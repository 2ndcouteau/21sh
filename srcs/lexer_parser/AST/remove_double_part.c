/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_double_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:06:45 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:44:17 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	free_rest_of_list(t_cut_line **browse_tmp, t_cut_line **relay_tmp,
									t_cut_line **begin_list, int *nb_open_char)
{
	t_cut_line	*tmp;

	while (*nb_open_char > 0 && *browse_tmp != NULL)
	{
		if ((*browse_tmp)->special_char != NULL)
		{
			if (!ft_isthischar("{[(", (*browse_tmp)->special_char[0]))
				++*nb_open_char;
			else if (!ft_isthischar("}])", (*browse_tmp)->special_char[0]))
				--*nb_open_char;
		}
		tmp = *browse_tmp;
		if (*relay_tmp == *browse_tmp)
		{
			*relay_tmp = (*relay_tmp)->right;
			if (*relay_tmp != NULL)
				(*relay_tmp)->left = NULL;
			*begin_list = *relay_tmp;
		}
		*browse_tmp = (*browse_tmp)->right;
		tmp = free_node_list(tmp);
	}
}

static void	link_parts_list(t_cut_line **browse_tmp, t_cut_line **relay_tmp,
														t_cut_line **begin_list)
{
	if (*relay_tmp != NULL)
	{
		(*relay_tmp)->right = *browse_tmp;
		(*browse_tmp)->left = *relay_tmp;
	}
	else
	{
		if (*browse_tmp != NULL)
			(*browse_tmp)->left = NULL;
		*relay_tmp = *browse_tmp;
		*begin_list = *browse_tmp;
	}
}

static void	check_open_double(t_cut_line **browse_tmp, t_cut_line **relay_tmp,
											t_cut_line **begin_list, char *mark)
{
	int			nb_open_char;
	t_cut_line	*tmp;

	nb_open_char = 0;
	if (!ft_isthischar("{[(", (*browse_tmp)->special_char[0]))
	{
		tmp = *browse_tmp;
		if (*browse_tmp == *begin_list)
			*relay_tmp = NULL;
		*browse_tmp = (*browse_tmp)->right;
		tmp = free_node_list(tmp);
		++nb_open_char;
		link_parts_list(browse_tmp, relay_tmp, begin_list);
		free_rest_of_list(browse_tmp, relay_tmp, begin_list, &nb_open_char);
		*mark = 1;
	}
}

static void	link_relay_browse(t_cut_line **browse_tmp, t_cut_line **relay_tmp)
{
	if (*relay_tmp != *browse_tmp)
	{
		if (*browse_tmp != NULL)
			(*browse_tmp)->left = *relay_tmp;
		if (*relay_tmp != NULL)
			(*relay_tmp)->right = *browse_tmp;
	}
}

t_cut_line	*remove_double_part(t_cut_line *begin_list)
{
	t_cut_line	*browse_tmp;
	t_cut_line	*relay_tmp;
	char		mark;

	browse_tmp = begin_list;
	relay_tmp = browse_tmp;
	while (browse_tmp != NULL)
	{
		mark = 0;
		if (browse_tmp->value_token == VALUE_TOKEN_COMMAND)
		{
			if (browse_tmp->special_char != NULL)
			{
				check_open_double(&browse_tmp, &relay_tmp, &begin_list, &mark);
				link_relay_browse(&browse_tmp, &relay_tmp);
			}
		}
		if (browse_tmp != NULL && mark == 0)
		{
			relay_tmp = browse_tmp;
			browse_tmp = browse_tmp->right;
		}
	}
	return (begin_list);
}
