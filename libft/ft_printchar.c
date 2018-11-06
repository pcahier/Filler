/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:31:19 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/15 19:45:12 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printchar(t_stru *stru, unsigned int c, int fd)
{
	int		ret;

	if (stru->len == -1)
		return (-1);
	ret = stru->len;
	if (!stru->l_just)
	{
		while (stru->wid_min > ret && !stru->zero)
			ret = ret + ft_putchar_fd(' ', fd);
		while (stru->wid_min > ret && stru->zero)
			ret = ret + ft_putchar_fd('0', fd);
	}
	ft_printwchar(stru, c, fd);
	if (stru->l_just)
		while (stru->wid_min > ret)
			ret = ret + ft_putchar_fd(' ', fd);
	return (ret);
}
