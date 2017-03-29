/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxp_create_special_char_node.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 19:57:45 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 14:46:21 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	init_list_cut_line_special_char(t_env **e, char *command_line,
													int pos_line, int pos_word)
{
	if (!((*e)->current_cmd->begin_list_cut_line =
									(t_cut_line*)malloc(sizeof(t_cut_line))))
		exit(EXIT_FAILURE);
	(*e)->current_cmd->last_node_list = (*e)->current_cmd->begin_list_cut_line;
	(*e)->current_cmd->begin_list_cut_line->right = NULL;
	(*e)->current_cmd->begin_list_cut_line->left = NULL;
	(*e)->current_cmd->begin_list_cut_line->special_char =
					lxp_dup_special_char(e, command_line, pos_line, pos_word);
	(*e)->current_cmd->begin_list_cut_line->len_special_char =
				ft_strlen((*e)->current_cmd->begin_list_cut_line->special_char);
	(*e)->current_cmd->begin_list_cut_line->value_token =
												(*e)->current_cmd->value_token;
	(*e)->current_cmd->begin_list_cut_line->command_part = NULL;
	(*e)->current_cmd->begin_list_cut_line->len_command_part = 0;
	if ((*e)->current_cmd->error_nbr != 0)
		return (-1);
	else
		return ((*e)->current_cmd->begin_list_cut_line->len_special_char);
}

static int	add_node_list_cut_line_special_char(t_env **e,
								char *command_line, int pos_line, int pos_word)
{
	t_cut_line	*new_node;

	new_node = (*e)->current_cmd->last_node_list;
	if (!(new_node->right = (t_cut_line*)malloc(sizeof(t_cut_line))))
		exit(EXIT_FAILURE);
	new_node->right->left = new_node;
	new_node = new_node->right;
	(*e)->current_cmd->last_node_list = new_node;
	new_node->right = NULL;
	new_node->special_char = lxp_dup_special_char(e, command_line,
															pos_line, pos_word);
	new_node->len_special_char = ft_strlen(new_node->special_char);
	new_node->value_token = (*e)->current_cmd->value_token;
	new_node->command_part = NULL;
	new_node->len_command_part = 0;
	if ((*e)->current_cmd->error_nbr != 0)
		return (-1);
	else
		return (new_node->len_special_char);
}

int			create_special_char_node(t_env **e, char *command_line,
													int pos_line, int pos_word)
{
	int			ret;

	if (command_line[pos_line + pos_word] == '\0')
		return (0);
	if (command_line[pos_line + pos_word] == '#')
		return (-1);
	if ((*e)->current_cmd->begin_list_cut_line == NULL)
		ret = init_list_cut_line_special_char(e, command_line, pos_line,
																	pos_word);
	else
		ret = add_node_list_cut_line_special_char(e, command_line, pos_line,
																	pos_word);
	return (ret);
}
