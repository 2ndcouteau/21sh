/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 00:08:39 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 23:23:20 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		init_and_set_struct_for_input(char *command_line, t_env **e)
{
	ft_bzero(command_line, MAX_LEN_COMMAND);
	ft_bzero((*e)->posicao->buffer_line, MAX_LEN_COMMAND);
	reinitialisation_posicao(e);
	term_set_cursor_position((*e)->posicao);
	term_copy_hist_list(e);
	(*e)->posicao->current_history = NULL;
	singleton_t_posicao((*e)->posicao);
	singleton_t_env(*e);
	init_tab_count_new_command((*e)->tab_count);
}

static bool	get_one_input(char *buffer)
{
	ft_bzero(buffer, 8);
	if (term_get_input(buffer))
		return (ERROR);
	return (SUCCESS);
}

static bool	sh_enter_input(t_env **e, char *command_line, int *ret_status)
{
	int		start;

	start = ft_strlen(command_line);
	if ((*e)->tab_count->heredoc_mode == NO_HEREDOC ||
								(*e)->tab_count->heredoc_mode == HEREDOC_FINISH)
		term_str_add_cpy(e, command_line);
	*ret_status = lexpar_check_main(e, command_line,
											(*e)->posicao->buffer_line, start);
	if ((*ret_status == SUCCESS || *ret_status == 2) &&
											(*e)->tab_count->back_slash == 0)
	{
		if ((*e)->tab_count->diese == 0)
			ft_putchar('\n');
		free_copy_hist_list(e);
		return (SUCCESS);
	}
	suppr_back_slash(command_line, (*e)->posicao, (*e)->tab_count);
	print_waiting_prompt((*e)->tab_count, 1);
	reinitialisation_posicao_waiting_mode((*e)->posicao, (*e)->tab_count);
	term_set_cursor_position((*e)->posicao);
	ft_bzero((*e)->posicao->buffer_line, MAX_LEN_COMMAND);
	return (ERROR);
}

int			sh_get_input(char *command_line, t_env **e)
{
	char	buffer[8];
	int		ret_status;

	enable_termcaps();
	init_and_set_struct_for_input(command_line, e);
	while (1)
	{
		if (get_one_input(buffer))
			return (ERROR);
		if ((long int)*buffer == ENTER)
		{
			if (!sh_enter_input(e, command_line, &ret_status))
				break ;
		}
		else
			term_check_input(e, buffer, (*e)->posicao->buffer_line);
	}
	disable_termcaps();
	return (ret_status);
}
