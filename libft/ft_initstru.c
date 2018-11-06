/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstru.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:00:16 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 19:52:39 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stru			*ft_genbasestru(t_stru *stru, size_t pre, size_t wid_min)
{
	stru->pre = pre;
	stru->wid_min = wid_min;
	stru->l_just = 0;
	stru->sign = 0;
	stru->zero = 0;
	stru->pound = 0;
	stru->conv = 0;
	stru->len = 0;
	return (stru);
}
