/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:40:47 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 17:07:18 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstring(t_stru *stru, char *str, int fd)
{
	int		ret;
	int		len;

	ret = 0;
	len = ft_strlen(str);
	if (!stru->l_just)
	{
		while (stru->wid_min - (len > stru->pre ? stru->pre : len) > ret
				&& !stru->zero)
			ret = ret + ft_putchar_fd(' ', fd);
		while (stru->wid_min - (len > stru->pre ? stru->pre : len) > ret
				&& stru->zero)
			ret = ret + ft_putchar_fd('0', fd);
	}
	if (stru->pre && len)
	{
		if (stru->pre < len)
			ret = ret + ft_putnstr_fd(str, fd, stru->pre);
		else
			ret = ret + ft_putstr_fd(str, fd);
	}
	if (stru->l_just)
		while (stru->wid_min > ret)
			ret = ret + ft_putchar_fd(' ', fd);
	return (ret);
}
