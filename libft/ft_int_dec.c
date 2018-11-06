/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:18:14 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 19:54:08 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_formatintdec(intmax_t s, t_stru *stru)
{
	stru->len = ft_printdecnumlen(s);
	return (ft_itoa_print((intmax_t)s, stru));
}

static char		*ft_switch_int(intmax_t s, t_stru *stru, char *str)
{
	if (stru->conv == 0)
		str = ft_formatintdec((int)s, stru);
	else if (stru->conv == 1)
		str = ft_formatintdec((long int)s, stru);
	else if (stru->conv == 2)
		str = ft_formatintdec((long long int)s, stru);
	else if (stru->conv == 3)
		str = ft_formatintdec(s, stru);
	else if (stru->conv == 4)
		str = ft_formatintdec((ssize_t)s, stru);
	else if (stru->conv == -1)
		str = ft_formatintdec((short)s, stru);
	else if (stru->conv == -2)
		str = ft_formatintdec((char)s, stru);
	return (str);
}

int				ft_int_dec(const char *format, va_list *ap, int fd)
{
	t_stru		stru;
	intmax_t	s;
	char		*str;

	str = NULL;
	ft_genbasestru(&stru, -1, 0);
	ft_analyseformat(&stru, format);
	ft_analyseformat2(&stru, format);
	ft_analyseformat3(&stru, format, ap);
	s = va_arg(*ap, intmax_t);
	str = ft_switch_int(s, &stru, str);
	s = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (s);
}
