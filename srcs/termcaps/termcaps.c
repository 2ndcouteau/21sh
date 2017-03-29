/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:36:44 by qrosa             #+#    #+#             */
/*   Updated: 2017/02/10 20:46:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

int		init_termcaps(char **env)
{
	char			*term_name;

	if (*env == NULL)
	{
		ft_putendl_fd("21sh: A TERM valid is necessary. QUIT.", 2);
		return (1);
	}
	if (isatty(STDIN_FILENO) == 0)
	{
		ft_putendl_fd("21sh: Error: STDIN_FILENO unvailable. QUIT", 2);
		return (1);
	}
	if ((term_name = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("21sh: A TERM valid is necessary.", 2);
		return (1);
	}
	if (tgetent(NULL, term_name) != 1)
	{
		ft_putendl_fd("21sh: TERM value is not compatible", STDERR_FILENO);
		return (1);
	}
	return (0);
}

int		disable_termcaps(void)
{
	struct termios term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO | ISIG);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
		return (-1);
	return (0);
}

bool	enable_termcaps(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) != -1)
	{
		term.c_lflag &= ~(ICANON | ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term) != -1)
			return (0);
	}
	return (1);
}
