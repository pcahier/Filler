/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:02:42 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/07 19:03:32 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fil_map(char *line, struct s_filler *inf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < inf->dim[1])
	{
		while (x < inf->dim[0])
		{
			if (line[x + 4] == inf->op_piece)
				inf->coord[x][y] = -1;
			else if (line[x + 4] == inf->my_piece)
				inf->coord[x][y] = -2;
			x++;
		}
	x = 0;
	y++;
	get_next_line(0, &line);
	}
}

void		play_filler(char *line, struct s_filler *inf)
{
	ft_printf("1 2\n");
	fil_map(line, inf);
}
