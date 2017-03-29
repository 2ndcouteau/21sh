/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_node_command_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:09:46 by yoko              #+#    #+#             */
/*   Updated: 2017/02/09 16:32:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	move_node_command_part(t_cut_line **browse_tmp, t_cut_line **relay_tmp,
														t_cut_line **begin_tmp)
{
	t_cut_line	*tmp;

	tmp = (*browse_tmp)->right;
	(*browse_tmp)->right = tmp->right;
	if (tmp->right != NULL)
		tmp->right->left = *browse_tmp;
	if ((*relay_tmp)->value_token == VALUE_TOKEN_COMMAND)
	{
		tmp->right = (*relay_tmp)->right;
		if ((*relay_tmp)->right != NULL)
			(*relay_tmp)->right->left = tmp;
		(*relay_tmp)->right = tmp;
		tmp->left = *relay_tmp;
		*relay_tmp = (*relay_tmp)->right;
	}
	else
	{
		tmp->right = *begin_tmp;
		tmp->right->left = tmp;
		tmp->left = NULL;
		*relay_tmp = tmp;
		*begin_tmp = tmp;
	}
}
