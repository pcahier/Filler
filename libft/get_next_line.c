/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:52:16 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/29 16:06:27 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_strsubfree(char *s, unsigned int start, size_t len)
{
	char			*cop;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(cop = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		cop[i] = s[start + i];
		i++;
	}
	cop[i] = '\0';
	free(s);
	return (cop);
}

static int			give_next_line(char **tab, int fd, char **str)
{
	char	*point;
	size_t	len;

	len = ft_atoi(tab[fd + OPEN_MAX]);
	if (!(point = ft_memchr(tab[fd], '\n', len)))
		point = tab[fd] + len;
	if (len == 0)
	{
		return (0);
	}
	if (*point == '\n')
		point += 1;
	free(tab[fd + OPEN_MAX]);
	tab[fd + OPEN_MAX] = ft_itoa(len + (tab[fd] - point));
	*str = ft_strsub(tab[fd], 0,
		(point - tab[fd]) - (*(point - 1) == '\n' ? 1 : 0));
	tab[fd] = ft_strsubfree(tab[fd], point - tab[fd],
								ft_atoi(tab[fd + OPEN_MAX]));
	return (1);
}

static char			*ft_memcatget(char *src, char *src2, size_t sizo,
						size_t sizt)
{
	char			*dst;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(dst = (char *)ft_memalloc(sizt + 1)))
		return (NULL);
	while (i < sizo)
	{
		dst[i] = src[i];
		i++;
	}
	while (i + j < sizt)
	{
		dst[i + j] = src2[j];
		j++;
	}
	dst[i + j] = '\0';
	if (src)
		free(src);
	return (dst);
}

static int			read_and_stock(const int fd, char **tab, char **line)
{
	char	*buf;
	char	*str;
	int		ret;
	int		count;

	count = 0;
	str = NULL;
	ret = 1;
	if (!(buf = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		if (!(str = ft_memcatget(str, buf, count, count + ret)))
			return (-1);
		count += ret;
	}
	free(buf);
	tab[fd] = str;
	tab[fd + OPEN_MAX] = ft_itoa(count);
	return (give_next_line(tab, fd, line));
}

int					get_next_line(const int fd, char **line)
{
	static char		*tab[OPEN_MAX * 2];
	int				ret;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFF_SIZE < 1)
		return (-1);
	if (tab[fd])
		return (give_next_line(tab, fd, line));
	if ((ret = read_and_stock(fd, tab, line)) == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	return (1);
}
