/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoko <yoko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:47:10 by yoko              #+#    #+#             */
/*   Updated: 2017/02/09 13:58:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

t_cut_line	*clean_list(t_cut_line *begin_list)
{
	begin_list = remove_double_part(begin_list);
	if (begin_list == NULL)
		return (NULL);
	begin_list = sort_command_line(begin_list);
	return (begin_list);
}
