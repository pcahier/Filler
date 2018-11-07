/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:04:10 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/07 19:03:29 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		free_map(struct s_filler *inf)
{
	while (inf->dim[0] >= 0)
	{
		free(inf->coord[inf->dim[0]]);
		inf->dim[0]--;
	}
	free(inf->coord);
}

static int		allocate_map(struct s_filler *inf)
{
	int		i;
	
	i = 0;
	if(!(inf->coord = (int**)ft_memalloc(sizeof(int *) * (inf->dim[0] + 1))))
		return (0);
	while (i < inf->dim[0])
	{
		if(!(inf->coord[i] = (int*)ft_memalloc(sizeof(int) * 
						(inf->dim[1] + 1 ))))
			return (0);
		i++;
	}
	return (1);
}

static int		init_inf(char *line, struct s_filler *inf)
{
	get_next_line(0, &line);
	inf->play = line[10] - '0';
	inf->my_piece = (inf->play == 1 ? 'X' : 'O');
	inf->op_piece = (inf->play == 1 ? 'O' : 'X');
	get_next_line(0, &line);
	inf->dim[0] = ft_atoi(line + 8);
	inf->dim[1] = ft_atoi(line + 8 + ft_decnumlen(inf->dim[0]));
	if (!(allocate_map(inf)))
		return (0);
	return (1);
}

int				main(void)
{
	char				*line;
	struct s_filler		inf;
	

	line = NULL;
	if (!(init_inf(line, &inf)))
		return (-1);
	play_filler(line, &inf);
	free_map(&inf);
	return (0);
}	
