/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:17:56 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/14 18:36:55 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				skip_next_line(const int fd, char *line)
{
	get_next_line(fd, &line);
	free(line);
	return (1);
}
