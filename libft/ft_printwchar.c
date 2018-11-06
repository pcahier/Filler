/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 07:11:09 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/15 19:26:46 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fourbytes(unsigned int s, int fd)
{
	unsigned char	tab[4];
	int				i;

	tab[3] = 128;
	tab[2] = 128;
	tab[1] = 128;
	tab[0] = 240;
	i = 0;
	tab[3] += s % 64;
	s /= 64;
	tab[2] += s % 64;
	s /= 64;
	tab[1] += s % 64;
	s /= 64;
	tab[0] += s;
	write(fd, tab, 4);
	return (4);
}

static int	ft_threebytes(unsigned int s, int fd)
{
	unsigned char	tab[3];
	int				i;

	tab[2] = 128;
	tab[1] = 128;
	tab[0] = 224;
	i = 0;
	tab[2] += s % 64;
	s /= 64;
	tab[1] += s % 64;
	s /= 64;
	tab[0] += s;
	write(fd, tab, 3);
	return (3);
}

static int	ft_twobytes(unsigned int s, int fd)
{
	unsigned char	tab[2];
	int				i;

	tab[1] = 128;
	tab[0] = 192;
	i = 0;
	tab[1] += s % 64;
	s /= 64;
	tab[0] += s;
	write(fd, tab, 2);
	return (2);
}

static int	ft_onebyte(unsigned int s, int fd)
{
	return (ft_putchar_fd(s, fd));
}

int			ft_printwchar(t_stru *stru, unsigned int s, int fd)
{
	if (stru->len <= 1)
		return (ft_onebyte(s, fd));
	else if (stru->len == 2)
		return (ft_twobytes(s, fd));
	else if (stru->len == 3)
		return (ft_threebytes(s, fd));
	else
		return (ft_fourbytes(s, fd));
}
