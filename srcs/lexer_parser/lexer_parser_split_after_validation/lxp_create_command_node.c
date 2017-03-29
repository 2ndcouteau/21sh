/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_create_command_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 23:27:36 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 14:29:56 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	init_list_cut_line(t_env **e, char *command_line, int pos_line,
																int pos_word)
{
	if (!((*e)->current_cmd->begin_list_cut_line =
									(t_cut_line*)malloc(sizeof(t_cut_line))))
		exit(EXIT_FAILURE);
	(*e)->current_cmd->last_node_list = (*e)->current_cmd->begin_list_cut_line;
	(*e)->current_cmd->begin_list_cut_line->right = NULL;
	(*e)->current_cmd->begin_list_cut_line->left = NULL;
	(*e)->current_cmd->begin_list_cut_line->special_char = NULL;
	(*e)->current_cmd->begin_list_cut_line->len_special_char = 0;
	(*e)->current_cmd->begin_list_cut_line->command_part =
							ft_str_trimndup(command_line, pos_line, pos_word);
	(*e)->current_cmd->begin_list_cut_line->len_command_part =
				ft_strlen((*e)->current_cmd->begin_list_cut_line->command_part);
	(*e)->current_cmd->begin_list_cut_line->value_token = VALUE_TOKEN_COMMAND;
}

static void	add_node_list_cut_line(t_env **e, char *command_line, int pos_line,
																int pos_word)
{
	t_cut_line	*new_node;

	new_node = (*e)->current_cmd->last_node_list;
	if (!(new_node->right = (t_cut_line*)malloc(sizeof(t_cut_line))))
		exit(EXIT_FAILURE);
	new_node->right->left = new_node;
	new_node = new_node->right;
	(*e)->current_cmd->last_node_list = new_node;
	new_node->right = NULL;
	new_node->special_char = NULL;
	new_node->len_special_char = 0;
	new_node->command_part = ft_str_trimndup_echap(command_line, pos_line,
																	pos_word);
	new_node->len_command_part = ft_strlen(new_node->command_part);
	new_node->value_token = VALUE_TOKEN_COMMAND;
	new_node = NULL;
}

char		check_empty_end_command(char *command_line, int pos_line,
																int pos_word)
{
	int			i;

	i = 0;
	while (i < pos_word)
	{
		if (ft_isthischar(" \n\t", command_line[pos_line + i]))
			return (0);
		i++;
	}
	return (1);
}

void		create_command_node(t_env **e, char *command_line, int pos_line,
																int pos_word)
{
	int			offset;

	offset = 0;
	if ((*e)->current_cmd->begin_list_cut_line == NULL)
		init_list_cut_line(e, command_line, pos_line, pos_word);
	else
	{
		if ((*e)->current_cmd->last_node_list != NULL &&
	((*e)->current_cmd->last_node_list->value_token ==
	VALUE_TOKEN_IN_REDIRECTION || (*e)->current_cmd->last_node_list->value_token
												== VALUE_TOKEN_OUT_REDIRECTION))
		{
			offset = count_offset_redirection_name(e, command_line, pos_line,
																	pos_word);
			add_node_list_cut_line(e, command_line, pos_line, offset);
		}
		if (!check_empty_end_command(command_line, (pos_line + offset),
														(pos_word - offset)))
			add_node_list_cut_line(e, command_line, (pos_line + offset),
														(pos_word - offset));
	}
}
