/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_init_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:39:56 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add a new bool for each new option and init it to 0.
*/

static void	ls_init_opt(t_opt **e)
{
	(*e)->opt_b->a = 0;
}

void		opt_init_env(t_opt **e, char **init)
{
	(*e)->define = init;
	init = NULL;
	(*e)->position = 1;
	(*e)->opt = NULL;
	(*e)->opt_all = NULL;
	(*e)->l_opt = NULL;
	(*e)->nb_arg = 0;
	(*e)->s_arg = NULL;
	(*e)->bad_char = 0;
	(*e)->error = 0;
	(*e)->mark = 1;
	if (!((*e)->opt_b = (t_bool*)malloc(sizeof(t_bool))))
		(*e)->error = 1;
	ls_init_opt(e);
}
