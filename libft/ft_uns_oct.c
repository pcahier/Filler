/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:16:49 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 19:55:09 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_formatintdec(uintmax_t s, t_stru *stru)
{
	stru->len = ft_printunsnumlen(s, 8);
	return (ft_uitoa_print(s, stru, 8));
}

static char		*ft_switch_oct(uintmax_t s, t_stru *stru, char *str)
{
	if (stru->conv == 0)
		str = ft_formatintdec((unsigned int)s, stru);
	else if (stru->conv == 1)
		str = ft_formatintdec((unsigned long int)s, stru);
	else if (stru->conv == 2)
		str = ft_formatintdec((unsigned long long int)s, stru);
	else if (stru->conv == 3)
		str = ft_formatintdec(s, stru);
	else if (stru->conv == 4)
		str = ft_formatintdec((size_t)s, stru);
	else if (stru->conv == -1)
		str = ft_formatintdec((unsigned short int)s, stru);
	else if (stru->conv == -2)
		str = ft_formatintdec((unsigned char)s, stru);
	return (str);
}

int				ft_uns_oct(const char *format, va_list *ap, int fd)
{
	t_stru		stru;
	uintmax_t	s;
	char		*str;

	str = NULL;
	ft_genbasestru(&stru, -1, 0);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format, ap);
	s = va_arg(*ap, uintmax_t);
	str = ft_switch_oct(s, &stru, str);
	s = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (s);
}
