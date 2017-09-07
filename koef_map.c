/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koef_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:57:02 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/07 19:52:51 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_abs(int *i)
{
	if (*i < 0)
		*i *= -1;
}

int		**alloc(int h, int w)
{
	int	**ret;
	int i;
	int j;

	ret = (int**)malloc(sizeof(int*) * h);
	i = 0;
	j = 0;
	while (i < h)
	{
		ret[i] = (int*)malloc(sizeof(int) * w);
		while (j < w)
		{
			ret[i][j] = -1;
			j++;
		}
		i++;
	}
	return (ret);
}

void	koef_count(t_flr *s, int h, int w)
{
	int	th;
	int	tw;

	th = 0;
	tw = 0;
	while (th < s->m_h)
	{
		while (tw < s->m_w)
		{
			if ((tw - w) > (th - h))
				s->kmap[th][tw] = (tw - w);
			else if ((tw - w) < (th - h))
				s->kmap[th][tw] = (th - h);
			tw++;
		}
		th++;
	}
}

void	koef_map(t_flr *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s->kmap = alloc(s->m_h, s->m_w);
	while (i < s->m_h)
	{
		while (j < s->m_w)
		{
			if (s->map[i][j] == s->e_char && s->kmap[i][j] != 0)
				koef_count(s, i, j);
			j++;
		}
		i++;
	}





	int fd = open("test_out", O_RDWR);
	i = 0;
	j = 0;
	while (i < s->m_h)
	{
		while (j < s->m_w)
		{
			dprintf(fd, "%d ", s->kmap[i][j]);
			j++;
		}
		dprintf(fd, "\n");
		i++;
	}
}
