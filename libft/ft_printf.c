/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:54:04 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/05 18:43:25 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	ret = ft_vfprintf(1, format, &ap);
	va_end(ap);
	return (ret);
}
