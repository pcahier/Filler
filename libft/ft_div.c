/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:51:50 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/14 13:57:30 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_div	ft_div(int num, int denom)
{
	t_div	out;

	if (denom == 0)
	{
		out.quot = 0;
		out.rem = 0;
	}
	out.quot = num / denom;
	out.rem = num % denom;
	return (out);
}
