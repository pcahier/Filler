/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:32 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/14 18:37:57 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include "libft.h"
# ifndef BUFF_SIZE
#  define BUFF_SIZE 1024
# endif

int				get_next_line(const int fd, char **line);
int				skip_next_line(const int fd, char *line);

#endif
