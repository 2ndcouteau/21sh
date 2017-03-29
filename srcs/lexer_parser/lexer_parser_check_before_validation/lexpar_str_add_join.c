/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexpar_str_add_join.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristal <cristal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 23:02:55 by cristal           #+#    #+#             */
/*   Updated: 2017/02/09 17:35:37 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/sh21.h>

static void	copy_end_line(char *dst, char *src, int i)
{
	int a;

	a = 0;
	while (src[a] != '\0')
	{
		dst[i] = src[a];
		a++;
		i++;
	}
	dst[i] = '\0';
}

static int	check_len(char *dst, char *src)
{
	int len;

	len = ft_strlen(src);
	if (dst != NULL)
		len += ft_strlen(dst) + 1;
	return (len);
}

static int	add_back_space(char **tmp, int i)
{
	if (i > 0)
	{
		(*tmp)[i] = '\n';
		return (1);
	}
	return (0);
}

char		*lexpar_str_add_join(char *dst, char *src)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = check_len(dst, src);
	if (!(tmp = (char*)malloc(sizeof(char) * len + 1)))
		exit(ERROR);
	if (dst != NULL)
	{
		while (dst[i] != '\0')
		{
			tmp[i] = dst[i];
			i++;
		}
	}
	i += add_back_space(&tmp, i);
	copy_end_line(tmp, src, i);
	if (dst != NULL)
		free(dst);
	dst = tmp;
	tmp = NULL;
	return (dst);
}
