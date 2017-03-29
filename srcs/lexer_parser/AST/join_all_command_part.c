/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_all_command_part.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:29:42 by qrosa             #+#    #+#             */
/*   Updated: 2017/01/19 11:24:26 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static int	count_len_total(t_cut_line **relay_tmp)
{
	int len_total;

	len_total = (*relay_tmp)->len_command_part;
	while ((*relay_tmp)->left != NULL && (*relay_tmp)->left->value_token == \
	VALUE_TOKEN_COMMAND)
	{
		++len_total;
		len_total += (*relay_tmp)->left->len_command_part;
		*relay_tmp = (*relay_tmp)->left;
	}
	(*relay_tmp)->len_command_part = len_total;
	return (len_total);
}

static int	switch_first_elem(t_cut_line **relay_tmp, int len_total)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((tmp = ft_memalloc(len_total + 1)) == NULL)
		exit(EXIT_FAILURE);
	while ((*relay_tmp)->command_part[i] != '\0')
	{
		tmp[i] = (*relay_tmp)->command_part[i];
		++i;
	}
	tmp[i] = '\0';
	free((*relay_tmp)->command_part);
	(*relay_tmp)->command_part = tmp;
	tmp = NULL;
	return (i);
}

static int	add_str(char *total_buff, char *str, int position)
{
	int a;

	a = 0;
	total_buff[position] = ' ';
	++position;
	while (str[a] != '\0')
	{
		total_buff[position] = str[a];
		++position;
		++a;
	}
	total_buff[position] = '\0';
	++a;
	return (a);
}

static void	copy_rest_command_part(t_cut_line **relay_tmp, int position)
{
	t_cut_line	*tmp;

	while ((*relay_tmp)->right != NULL && (*relay_tmp)->right->value_token ==\
	VALUE_TOKEN_COMMAND)
	{
		tmp = (*relay_tmp)->right;
		position += add_str((*relay_tmp)->command_part, tmp->command_part,\
	position);
		(*relay_tmp)->right = tmp->right;
		if (tmp->right != NULL)
			tmp->right->left = *relay_tmp;
		tmp = free_node_list(tmp);
	}
}

void		join_all_command_part(t_cut_line **relay_tmp)
{
	int			len_total;
	int			position;

	if (*relay_tmp != NULL)
	{
		len_total = count_len_total(relay_tmp);
		position = switch_first_elem(relay_tmp, len_total);
		copy_rest_command_part(relay_tmp, position);
	}
}
