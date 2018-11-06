/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstringwchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:12:02 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 19:46:13 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printstringwchar2(t_stru *stru, unsigned int *str, int fd,
				int ret)
{
	int len;

	len = stru->len;
	while (len > 0 && stru->pre > 0)
	{
		stru->len = 0;
		stru->pre -= ft_formatwchar(*str, stru);
		if (stru->pre >= 0)
		{
			ret = ret + ft_printwchar(stru, *str, fd);
			str++;
			len -= stru->len;
		}
	}
	while (stru->wid_min > ret)
		ret = ret + ft_putchar_fd(' ', fd);
	return (ret);
}

static int	ft_wcharlen(t_stru *stru, unsigned int *str, int *ret)
{
	int		ind;

	ind = 0;
	while (str[ind] != 0)
	{
		*ret = ft_formatwchar(str[ind++], stru);
		if (stru->pre < stru->len)
		{
			stru->len -= *ret;
			break ;
		}
		if (stru->len == -1)
			return (-1);
	}
	return (0);
}

int			ft_printstringwchar(t_stru *stru, unsigned int *str, int fd)
{
	int		ret;
	int		len;

	ret = 0;
	if (ft_wcharlen(stru, str, &ret) == -1)
		return (-1);
	len = stru->len;
	ret = 0;
	if (!stru->l_just)
	{
		while (stru->wid_min - (len > stru->pre ? stru->pre : len)
				> ret && !stru->zero)
			ret = ret + ft_putchar_fd(' ', fd);
		while (stru->wid_min - (len > stru->pre ? stru->pre : len)
				> ret && stru->zero)
			ret = ret + ft_putchar_fd('0', fd);
	}
	return (ft_printstringwchar2(stru, str, fd, ret));
}
