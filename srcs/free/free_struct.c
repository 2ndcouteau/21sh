/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:16:48 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:33:10 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		free_posicao_struct(t_env **e)
{
	if ((*e)->posicao != NULL)
	{
		(*e)->posicao->current_history = NULL;
		if ((*e)->posicao->copy_hist_begin != NULL)
		{
			while ((*e)->posicao->copy_hist_begin->next != NULL)
			{
				(*e)->posicao->copy_hist_begin =
										(*e)->posicao->copy_hist_begin->next;
				free((*e)->posicao->copy_hist_begin->prev);
				(*e)->posicao->copy_hist_begin->prev = NULL;
			}
			free((*e)->posicao->copy_hist_begin);
		}
		free((*e)->posicao);
		(*e)->posicao = NULL;
	}
}

t_cut_line	*free_ast(t_cut_line *ast)
{
	if (ast != NULL)
	{
		if (ast->left != NULL)
			free_ast(ast->left);
		if (ast->right != NULL)
			free_ast(ast->right);
		if (ast->command_part != NULL)
			ast->command_part = ft_free_line(&(ast->command_part));
		if (ast->special_char != NULL)
			ast->special_char = ft_free_line(&(ast->special_char));
		free(ast);
	}
	return (NULL);
}

t_cut_line	*free_list_command(t_cut_line *begin_list)
{
	t_cut_line *tmp;

	while (begin_list != NULL)
	{
		tmp = begin_list;
		begin_list = begin_list->right;
		tmp->right = NULL;
		tmp->left = NULL;
		if (tmp->command_part != NULL)
			tmp->command_part = ft_free_line(&(tmp->command_part));
		if (tmp->special_char != NULL)
			tmp->special_char = ft_free_line(&(tmp->special_char));
		free(tmp);
	}
	tmp = NULL;
	return (NULL);
}

void		free_cmd_struct(t_env **e)
{
	if ((*e)->current_cmd != NULL)
	{
		if ((*e)->current_cmd->line != NULL)
			(*e)->current_cmd->line = ft_free_line(&((*e)->current_cmd->line));
		if ((*e)->current_cmd->error_nbr == 0)
			(*e)->current_cmd->begin_list_cut_line =
							free_ast((*e)->current_cmd->begin_list_cut_line);
		else
			(*e)->current_cmd->begin_list_cut_line =
					free_list_command((*e)->current_cmd->begin_list_cut_line);
		(*e)->current_cmd->last_node_list = NULL;
		(*e)->current_cmd->line = NULL;
		(*e)->current_cmd->split_line -= (*e)->current_cmd->offset_mark;
		(*e)->current_cmd->split_line =
									ft_free_tab((*e)->current_cmd->split_line);
		(*e)->current_cmd->error_name =
								ft_free_line(&((*e)->current_cmd->error_name));
		free((*e)->current_cmd);
		(*e)->current_cmd = NULL;
	}
}
