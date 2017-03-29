/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:29:01 by yoko              #+#    #+#             */
/*   Updated: 2017/02/09 16:40:47 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	norm_function(t_cut_line **relay_tmp)
{
	t_cut_line	*browse_tmp;
	t_cut_line	*tmp;

	browse_tmp = *relay_tmp;
	while (browse_tmp->right != NULL && check_new_cmd(browse_tmp))
	{
		if (browse_tmp->right->value_token == VALUE_TOKEN_IN_REDIRECTION)
		{
			tmp = browse_tmp->right;
			if (tmp->right->right != NULL)
				tmp->right->right->left = browse_tmp;
			browse_tmp->right = tmp->right->right;
			tmp->right->right = (*relay_tmp)->right;
			if ((*relay_tmp)->right != NULL)
				(*relay_tmp)->right->left = tmp->right;
			tmp->left = *relay_tmp;
			(*relay_tmp)->right = tmp;
			if (browse_tmp == *relay_tmp)
				browse_tmp = browse_tmp->right->right;
			*relay_tmp = (*relay_tmp)->right->right;
		}
		else
			browse_tmp = browse_tmp->right;
	}
}

void		sort_input_redirection(t_cut_line **relay_tmp)
{
	if (*relay_tmp != NULL)
		norm_function(relay_tmp);
}
