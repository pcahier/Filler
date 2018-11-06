/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genprinstruc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:43:09 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 17:04:26 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isconvflag(const char c)
{
	if (c == '\'' || c == '-' || c == '+' || c == ' ' || c == '#' || c == 'h'
			|| c == 'l' || c == 'j' || c == 'z' || c == 't' || c == 'L'
				|| c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

void			ft_wildcard(t_stru *stru, const char *format, va_list *ap)
{
	if (*format == '*' && *(format - 1) != '.')
	{
		stru->wid_min = va_arg(*ap, int);
		if (stru->wid_min < 0)
		{
			stru->l_just = 1;
			stru->wid_min = ft_abs(stru->wid_min);
		}
	}
	if (*format == '*' && *(format - 1) == '.')
	{
		stru->pre = va_arg(*ap, int);
		if (stru->pre > 0)
			stru->zero = 0;
	}
	if (stru->pre > 10000000)
		stru->pre = 10000000;
	else if (stru->pre <= -1)
		stru->pre = -1;
	if (stru->wid_min > 10000000)
		stru->wid_min = 10000000;
}

void			ft_analyseformat3(t_stru *stru, const char *format,
		va_list *ap)
{
	while (ft_isconvflag(*format))
	{
		if (*format >= '1' && *format <= '9')
		{
			stru->wid_min = ft_atoi(format);
			while (*format >= '0' && *format <= '9')
				format++;
		}
		else if (*format == '*')
		{
			ft_wildcard(stru, format, ap);
			format++;
		}
		else if (*format == '.')
		{
			stru->pre = ft_atoi(format + 1);
			stru->zero = stru->pre > 0 ? 0 : stru->zero;
			format++;
			while (*format >= '0' && *format <= '9')
				format++;
		}
		else
			format++;
	}
	ft_wildcard(stru, format, ap);
}

t_stru			*ft_analyseformat2(t_stru *stru, const char *format)
{
	while (ft_isconvflag(*format))
		format++;
	if (*format == 'U' || *format == 'O' || *format == 'D' || *format == 'S'
			|| *format == 'C')
		stru->conv = 1;
	else if (*format == 'p')
		stru->conv = 5;
	else if (format[-1] == 'l' && format[-2] == 'l')
		stru->conv = 2;
	else if (format[-1] == 'l')
		stru->conv = 1;
	else if (format[-1] == 'h' && format[-2] == 'h')
		stru->conv = -2;
	else if (format[-1] == 'h')
		stru->conv = -1;
	else if (format[-1] == 'j')
		stru->conv = 3;
	else if (format[-1] == 'z')
		stru->conv = 4;
	return (stru);
}

t_stru			*ft_analyseformat(t_stru *stru, const char *format)
{
	while (ft_isconvflag(*format))
	{
		if (*format == '0' && !(*(format - 1) == '.' || (*(format - 1) >= '0'
						&& *(format - 1) <= '9')))
			stru->zero = 1;
		else if (*format == '-')
			stru->l_just = 1;
		else if (*format == '+')
			stru->sign = 2;
		else if (*format == ' ' && stru->sign < 2)
			stru->sign = 1;
		else if (*format == '#')
			stru->pound = 1;
		format++;
	}
	if (stru->l_just)
		stru->zero = 0;
	return (stru);
}
