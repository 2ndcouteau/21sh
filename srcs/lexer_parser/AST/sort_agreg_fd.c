/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_agreg_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:08:50 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 17:25:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	moove_agreg_fd(t_cut_line **relay_tmp, t_cut_line **browse_tmp,
															t_cut_line **tmp)
{
	*browse_tmp = *relay_tmp;
	while ((*browse_tmp)->right != NULL && check_new_cmd(*browse_tmp))
	{
		if ((*browse_tmp)->right->value_token == VALUE_TOKEN_AGREG_FD)
		{
			*tmp = (*browse_tmp)->right;
			(*browse_tmp)->right = (*tmp)->right;
			if ((*browse_tmp)->right != NULL)
				(*browse_tmp)->right->left = *browse_tmp;
			(*tmp)->right = (*relay_tmp)->right;
			if ((*tmp)->right != NULL)
				(*tmp)->right->left = *tmp;
			(*tmp)->left = *relay_tmp;
			(*relay_tmp)->right = *tmp;
			if (*browse_tmp == *relay_tmp)
				*browse_tmp = (*browse_tmp)->right;
			*relay_tmp = (*relay_tmp)->right;
		}
		else
			*browse_tmp = (*browse_tmp)->right;
	}
}

void		sort_agreg_fd(t_cut_line **relay_tmp)
{
	t_cut_line *browse_tmp;
	t_cut_line *tmp;
	t_cut_line *start_fd;

	if (*relay_tmp != NULL)
	{
		start_fd = *relay_tmp;
		moove_agreg_fd(relay_tmp, &browse_tmp, &tmp);
		if (start_fd->right != NULL && start_fd->right->value_token ==
														VALUE_TOKEN_AGREG_FD)
		{
			start_fd = start_fd->right;
			while (start_fd != *relay_tmp)
			{
				tmp = start_fd;
				start_fd = start_fd->right;
				start_fd->left = tmp->left;
				if (tmp->left != NULL)
					tmp->left->right = start_fd;
				tmp = free_node_list(tmp);
			}
		}
	}
}
