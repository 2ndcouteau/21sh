/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:48:29 by cristal           #+#    #+#             */
/*   Updated: 2017/01/10 23:50:46 by cristal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

t_cut_line	*free_node_list(t_cut_line *node)
{
	if (node != NULL)
	{
		node->left = NULL;
		node->right = NULL;
		if (node->command_part != NULL)
			node->command_part = ft_free_line(&(node->command_part));
		if (node->special_char != NULL)
			node->special_char = ft_free_line(&(node->special_char));
		free(node);
	}
	return (NULL);
}
