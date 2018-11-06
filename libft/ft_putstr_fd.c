/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:20:02 by pcahier           #+#    #+#             */
/*   Updated: 2017/12/10 19:12:44 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		write(fd, "(null)", 6);
	else
	{
		write(fd, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (0);
}
