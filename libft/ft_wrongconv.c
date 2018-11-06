/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrongconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:26:01 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 19:55:20 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wrongconv(const char *format, int fd, va_list *ap)
{
	int		i;
	int		ret;
	t_stru	stru;

	i = 0;
	ret = 0;
	ft_genbasestru(&stru, 1, 0);
	ft_analyseformat3(&stru, format, ap);
	ft_analyseformat2(&stru, format);
	ft_analyseformat(&stru, format);
	i = ft_strspn(format, FLAGSET);
	stru.len = format[i] ? 1 : 0;
	return (ft_printchar(&stru, format[i], fd));
}
