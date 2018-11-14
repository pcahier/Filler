/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:03:59 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/14 15:03:02 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_fil_piec
{
	int		col;
	int		lin;
	char	**coord;
	int		value;
	int		temp_x;
	int		temp_y;
}				t_fil_piec;

typedef struct	s_filler
{
	int		play;
	int		lin;
	int		col;
	int		**coord;
	char	my_piece;
	char	op_piece;
}				t_filler;

int				play_filler(char *line, struct s_filler *inf);
void			fil_heat(struct s_filler *inf);
void			put_piece(struct s_filler *inf, struct s_fil_piec *piec);

#endif
