/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:54:37 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 19:20:38 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsign(char *s, unsigned int neg, t_stru *stru)
{
	if (stru->sign == 1 && !neg)
		*s = ' ';
	else if (stru->sign == 2 && !neg)
		*s = '+';
	else if (neg)
		*s = '-';
}
