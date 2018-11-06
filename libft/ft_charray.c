/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:37:18 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 19:53:34 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_charray(const char *format, va_list *ap, int fd)
{
	t_stru			stru;
	unsigned int	*str;

	ft_genbasestru(&stru, INT_MAX, 0);
	ft_analyseformat3(&stru, format, ap);
	ft_analyseformat2(&stru, format);
	ft_analyseformat(&stru, format);
	if (stru.pre == -1)
		stru.pre = INT_MAX;
	str = va_arg(*ap, unsigned int*);
	if (str == NULL)
		return (ft_printstring(&stru, "(null)", fd));
	if (stru.conv != 1)
		return (ft_printstring(&stru, (char*)str, fd));
	return (ft_printstringwchar(&stru, str, fd));
}
