/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:28:43 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 17:33:45 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printstru.h"

static void	ft_vfcolor(int fd, const char *format, int *tab)
{
	int		ind;

	ind = 0;
	while (ind < 18)
	{
		if ((ft_strncmp(format, g_color[ind].chain,
						ft_strlen(g_color[ind].chain))) == 0)
		{
			ft_putstr_fd(g_color[ind].code, fd);
			tab[1] = ft_strlen(g_color[ind].chain) - 1;
			break ;
		}
		ind++;
	}
	if (ind == 18)
	{
		ft_putchar_fd('{', fd);
		tab[0]++;
	}
}

static int	ft_vfcomp(int fd, const char *format, va_list *ap, int *tab)
{
	tab[1] = ft_strspn(format + 1, FLAGSET) + 1;
	if (!format[tab[1]])
		return (-2);
	tab[2] = -1;
	while (tab[2]++ < 15)
	{
		if (format[tab[1]] == g_print[tab[2]].operat)
		{
			tab[3] = g_print[tab[2]].ft(format + 1, ap, fd);
			tab[0] = tab[0] + tab[3];
			if (tab[3] == -1)
				return (-1);
		}
	}
	if (tab[3] == -2)
		tab[0] = tab[0] + ft_wrongconv(format + 1, fd, ap);
	return (0);
}

int			ft_vfprintf(int fd, const char *format, va_list *ap)
{
	int				tab[5];

	tab[0] = 0;
	while (*format)
	{
		tab[1] = 0;
		tab[3] = -2;
		if (*format == '{')
			ft_vfcolor(fd, format, tab);
		else if (*format == '%')
		{
			tab[4] = ft_vfcomp(fd, format, ap, tab);
			if (tab[4] == -1)
				return (-1);
			else if (tab[4] == -2)
				break ;
		}
		else
		{
			ft_putchar_fd(*format, fd);
			tab[0]++;
		}
		format = format + tab[1] + 1;
	}
	return (tab[0] <= -1 ? -1 : tab[0]);
}
