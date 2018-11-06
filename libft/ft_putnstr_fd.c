/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:11:50 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/15 19:12:35 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr_fd(char const *s, int fd, int n)
{
	if (s == NULL)
		write(fd, "(null)", 6);
	else
	{
		write(fd, s, n);
		return (n);
	}
	return (0);
}
