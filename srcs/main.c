/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/09 19:04:45 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

void		check_header_parameters(void)
{
	if (HISTORICAL_LIMIT < 1)
	{
		ft_putendl_fd("ERROR: HISTORICAL_LIMIT < 1", 2);
		exit(EXIT_FAILURE);
	}
	if (MAX_LEN_COMMAND < 5)
	{
		ft_putendl_fd("ERROR: MAX_LEN_COMMAND < 5", 2);
		exit(EXIT_FAILURE);
	}
	if (MAX_LEN_COMMAND > 2147483647)
	{
		ft_putendl_fd(
			"ERROR: MAX_LEN_COMMAND is to big. Please choose <= 2147483647", 2);
		exit(EXIT_FAILURE);
	}
}

int			main(int ac, char **av, char **env)
{
	check_header_parameters();
	if (ac == 1 && av && env)
		sh_start_endless_loop(av, env);
	else
		sh_print_error(0, NULL);
	return (0);
}
