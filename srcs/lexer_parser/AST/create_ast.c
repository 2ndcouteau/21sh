/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 16:33:33 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 11:08:37 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

t_cut_line	*return_position_symbol(t_cut_line *list, int level)
{
	t_cut_line	*begin_list;

	begin_list = list;
	while (begin_list != NULL && level < 7)
	{
		if (level == 0 && begin_list->value_token == VALUE_TOKEN_SEMICOLON)
			return (begin_list);
		else if (level == 1 && (begin_list->value_token == VALUE_TOKEN_AND ||
									begin_list->value_token == VALUE_TOKEN_OR))
			return (begin_list);
		else if (level == 2 && begin_list->value_token == VALUE_TOKEN_PIPE)
			return (begin_list);
		else if (level == 3 && begin_list->value_token ==
													VALUE_TOKEN_OUT_REDIRECTION)
			return (begin_list);
		else if (level == 4 && begin_list->value_token ==
													VALUE_TOKEN_IN_REDIRECTION)
			return (begin_list);
		else if (level == 5 && begin_list->value_token == VALUE_TOKEN_AGREG_FD)
			return (begin_list);
		else if (level == 6)
			return (begin_list);
		begin_list = begin_list->right;
	}
	return (return_position_symbol(list, (level + 1)));
}

t_cut_line	*create_ast(t_env **e, t_cut_line *list, int level)
{
	t_cut_line *node_list;

	if (list == NULL)
		return (NULL);
	node_list = return_position_symbol(list, level);
	if (node_list != NULL)
	{
		if (node_list->left != NULL)
		{
			node_list->left->right = NULL;
			node_list->left = create_ast(e, list, (level + 1));
		}
		if (node_list->right != NULL)
		{
			node_list->right->left = NULL;
			node_list->right = create_ast(e, node_list->right, level);
		}
	}
	return (node_list);
}
