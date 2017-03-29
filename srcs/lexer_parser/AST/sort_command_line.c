/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_command_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:26:20 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:58:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static char	check_condition(t_cut_line *browse_tmp, t_cut_line *relay_tmp)
{
	if (browse_tmp->right == relay_tmp)
		return (0);
	else if (browse_tmp->value_token != VALUE_TOKEN_COMMAND)
		return (0);
	else if (browse_tmp->right == NULL)
		return (0);
	else if (browse_tmp->right != NULL && browse_tmp->value_token ==
VALUE_TOKEN_COMMAND && browse_tmp->right->value_token != VALUE_TOKEN_COMMAND)
		return (0);
	else
		return (1);
}

static void	place_start_sort(t_cut_line **begin_tmp,
								t_cut_line **browse_tmp, t_cut_line **relay_tmp)
{
	if (*begin_tmp != NULL && (*begin_tmp)->value_token >= VALUE_TOKEN_SEMICOLON
							&& (*begin_tmp)->value_token <= VALUE_TOKEN_PIPE)
		*browse_tmp = (*begin_tmp)->right;
	else
		*browse_tmp = *begin_tmp;
	*relay_tmp = *browse_tmp;
}

static void	supress_agreg_fd(t_cut_line **browse_tmp, t_cut_line **relay_tmp,
														t_cut_line **begin_tmp)
{
	t_cut_line *tmp;

	tmp = *browse_tmp;
	while (*browse_tmp != NULL && (*browse_tmp)->value_token ==
														VALUE_TOKEN_AGREG_FD)
		*browse_tmp = (*browse_tmp)->right;
	if ((*browse_tmp) != NULL && ((*browse_tmp)->value_token <
		VALUE_TOKEN_SEMICOLON || (*browse_tmp)->value_token > VALUE_TOKEN_PIPE))
	{
		if (*begin_tmp == tmp)
			*begin_tmp = *browse_tmp;
		if (*relay_tmp == tmp)
			*relay_tmp = *browse_tmp;
		*browse_tmp = tmp;
		while ((*browse_tmp)->value_token == VALUE_TOKEN_AGREG_FD)
		{
			*browse_tmp = (*browse_tmp)->right;
			if (tmp->left != NULL)
				tmp->left->right = *browse_tmp;
			(*browse_tmp)->left = tmp->left;
			tmp = free_node_list(tmp);
			tmp = *browse_tmp;
		}
		*browse_tmp = *relay_tmp;
	}
}

static void	browse_sort_command_line(t_cut_line **begin_tmp, t_cut_line
										**browse_tmp, t_cut_line **relay_tmp)
{
	while (*browse_tmp != NULL)
	{
		if ((*browse_tmp)->right != NULL && (*browse_tmp)->value_token ==
														VALUE_TOKEN_AGREG_FD)
			supress_agreg_fd(browse_tmp, relay_tmp, begin_tmp);
		if (browse_tmp != NULL)
		{
			if ((*browse_tmp)->right != NULL && (*browse_tmp)->value_token ==
VALUE_TOKEN_COMMAND && (*browse_tmp)->right->value_token == VALUE_TOKEN_COMMAND)
				move_node_command_part(browse_tmp, relay_tmp, begin_tmp);
			if (!check_condition(*browse_tmp, *relay_tmp))
				*browse_tmp = (*browse_tmp)->right;
			if (!check_new_cmd(*browse_tmp))
			{
				if ((*relay_tmp)->value_token == VALUE_TOKEN_COMMAND)
					join_all_command_part(relay_tmp);
				sort_agreg_fd(relay_tmp);
				sort_input_redirection(relay_tmp);
				*relay_tmp = (*browse_tmp)->right;
			}
		}
	}
}

t_cut_line	*sort_command_line(t_cut_line *begin_tmp)
{
	t_cut_line *browse_tmp;
	t_cut_line *relay_tmp;

	place_start_sort(&begin_tmp, &browse_tmp, &relay_tmp);
	browse_sort_command_line(&begin_tmp, &browse_tmp, &relay_tmp);
	if (relay_tmp != NULL)
	{
		if (relay_tmp->value_token == VALUE_TOKEN_COMMAND)
			join_all_command_part(&relay_tmp);
		sort_agreg_fd(&relay_tmp);
		sort_input_redirection(&relay_tmp);
	}
	return (begin_tmp);
}
