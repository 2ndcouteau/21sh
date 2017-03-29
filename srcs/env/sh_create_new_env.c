/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_create_new_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:40:11 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 16:30:26 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	save_env(t_env **e, char **env)
{
	int			len;

	len = ft_tablen(env) + 1;
	if (!((*e)->env = (char**)malloc(sizeof(char*) * len)))
		exit(EXIT_FAILURE);
	if (!((*e)->original_env = (char**)malloc(sizeof(char*) * len)))
		exit(EXIT_FAILURE);
	len = 0;
	while (env[len] != NULL)
	{
		(*e)->env[len] = ft_strdup(env[len]);
		(*e)->original_env[len] = ft_strdup(env[len]);
		len++;
	}
	(*e)->size_env = len;
	(*e)->env[len] = NULL;
	(*e)->original_env[len] = NULL;
}

static void	increase_shlvl(t_env **e)
{
	int			shlvl_pos;
	int			shlvl_value;
	char		*shlvl_char;

	if ((shlvl_pos = env_position_line(e, "SHLVL=", 6)) >= 0)
	{
		shlvl_value = ft_atoi((*e)->env[shlvl_pos] + 6);
		shlvl_value++;
		shlvl_char = ft_itoa(shlvl_value);
		env_replace_var((*e)->env, "SHLVL=", shlvl_char, shlvl_pos);
		shlvl_char = ft_free_line(&shlvl_char);
	}
	else
		setenv_var(e, "SHLVL", "1");
}

void		init_position(t_env **e)
{
	t_position	*posicao;

	if (!((*e)->posicao = (t_position*)malloc(sizeof(t_position))))
		exit(EXIT_FAILURE);
	posicao = (*e)->posicao;
	posicao->current_history = NULL;
	posicao->copy_hist_begin = NULL;
	ft_bzero(posicao->ptr_new_tmp, MAX_LEN_COMMAND);
	ft_bzero(posicao->buffer_line, MAX_LEN_COMMAND);
	ft_bzero(posicao->buffer_copy, MAX_LEN_COMMAND);
	posicao->len_prompt = ft_strlen(PROMPT);
	posicao->len_command = 0;
	posicao->heredoc_active = 0;
	posicao->len_full_command = 0;
	posicao->absolute_pos = posicao->len_prompt;
	posicao->x = 0;
	posicao->y = 0;
	posicao->x_end = 0;
	posicao->y_end = 0;
	posicao->x_win = 0;
	posicao->y_win = 0;
	posicao->waiting_mode = 0;
	posicao = NULL;
}

static void	create_tab_count(t_env **e)
{
	t_count		*tab_count;

	if (!((*e)->tab_count = (t_count*)malloc(sizeof(t_count))))
		exit(EXIT_FAILURE);
	tab_count = (*e)->tab_count;
	ft_bzero(tab_count->order_line, (MAX_LEN_COMMAND / 2));
	tab_count->order_position = 0;
	tab_count->status = 0;
	tab_count->len_waiting_prompt = 0;
	tab_count->pass = 0;
	tab_count->trim_space = 0;
	tab_count->heredoc_mode = NO_HEREDOC;
	tab_count->position_last_heredoc_word = 0;
	tab_count->heredoc_active = 0;
	tab_count->begin_list_heredoc = NULL;
	tab_count->check_position_heredoc = NULL;
	tab_count->last_word_heredoc = NULL;
	tab_count->back_slash = 0;
	tab_count->diese = 0;
	tab_count->parentheses = 0;
	tab_count->braces = 0;
	tab_count->brackets = 0;
	tab_count->error = 0;
	tab_count = NULL;
}

bool		create_new_env(t_env **e, char **env)
{
	if (!(*e = (t_env *)malloc(sizeof(t_env))))
		return (ERROR);
	(*e)->historical = NULL;
	(*e)->current_cmd = NULL;
	save_env(e, env);
	init_position(e);
	create_tab_count(e);
	increase_shlvl(e);
	return (SUCCESS);
}
