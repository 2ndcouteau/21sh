/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_start_endless_loop.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:41:31 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 23:24:44 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		sh_start_endless_loop(char **av, char **env)
{
	t_env	*e;

	e = NULL;
	if (init_termcaps(env))
		exit(EXIT_FAILURE);
	if (create_new_env(&e, env))
		exit(EXIT_FAILURE);
	while (1)
	{
		if ((sh_parsing_std_enter(av, &e)))
			break ;
	}
}
