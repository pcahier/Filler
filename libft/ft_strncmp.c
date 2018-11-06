/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:47:25 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/09 15:50:45 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	a;
	unsigned char	b;

	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		n--;
		a = *s1;
		b = *s2;
		if (a - b != 0)
			return (a - b);
		else
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
