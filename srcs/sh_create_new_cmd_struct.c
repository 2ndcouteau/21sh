/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_create_new_cmd_struct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:42:38 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 11:32:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	create_new_cmd_struct(t_env **e, char *command_line)
{
	if (command_line != NULL)
	{
		if (!((*e)->current_cmd = (t_cmd *)malloc(sizeof(t_cmd))))
			exit(EXIT_FAILURE);
		(*e)->current_cmd->line = ft_strdup(command_line);
		(*e)->current_cmd->size_line = ft_strlen(command_line);
		(*e)->current_cmd->split_line = NULL;
		(*e)->current_cmd->size_split_line = 0;
		(*e)->current_cmd->error_nbr = 0;
		(*e)->current_cmd->error_name = NULL;
		(*e)->current_cmd->offset_mark = 0;
		(*e)->current_cmd->nb_order_line = 0;
		(*e)->current_cmd->value_token = 0;
		(*e)->current_cmd->begin_list_cut_line = NULL;
		(*e)->current_cmd->last_node_list = NULL;
		lexer_parser_split_line_in_list(e, command_line);
		if ((*e)->current_cmd->error_nbr == 0)
		{
			(*e)->current_cmd->begin_list_cut_line =
							clean_list((*e)->current_cmd->begin_list_cut_line);
			(*e)->current_cmd->begin_list_cut_line =
					create_ast(e, (*e)->current_cmd->begin_list_cut_line, 0);
		}
	}
}
