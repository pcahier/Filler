/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 02:30:27 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 19:55:30 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_formatpointer(uintmax_t s, t_stru *stru)
{
	stru->len = ft_printunsnumlen(s, 16);
	stru->len += 2;
	return (ft_uitoa_print(s, stru, 16));
}

int				ft_pointer(const char *format, va_list *ap, int fd)
{
	t_stru			stru;
	uintmax_t		s;
	char			*str;

	ft_genbasestru(&stru, -1, 0);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format, ap);
	stru.pound = 1;
	s = va_arg(*ap, uintmax_t);
	str = ft_formatpointer(s, &stru);
	s = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (s);
}
