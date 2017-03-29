/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_call_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:31:55 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 23:43:28 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void	print_prompt_sig(int sig)
{
	t_env	*tmp_e;

	if (sig == SIGINT)
	{
		tmp_e = singleton_t_env(NULL);
		free_copy_hist_list(&tmp_e);
		free_list_heredoc(tmp_e->tab_count);
		init_and_set_struct_for_input(tmp_e->command_line, &tmp_e);
		ft_putchar('\n');
		ft_putstr(PROMPT);
	}
}

void	sig_do_nothing(int sig)
{
	if (sig == SIGTSTP)
		(void)sig;
}

void	sigint_sub(int sig)
{
	t_env	*tmp_e;

	if (sig == SIGINT)
	{
		tmp_e = singleton_t_env(NULL);
		free_copy_hist_list(&tmp_e);
		free_list_heredoc(tmp_e->tab_count);
		init_and_set_struct_for_input(tmp_e->command_line, &tmp_e);
	}
}

void	call_sub_signals(void)
{
	signal(SIGINT, sigint_sub);
	signal(SIGWINCH, replace_cursor_window);
}

void	call_signals(void)
{
	signal(SIGTSTP, sig_do_nothing);
	signal(SIGINT, print_prompt_sig);
	signal(SIGWINCH, replace_cursor_window);
}
