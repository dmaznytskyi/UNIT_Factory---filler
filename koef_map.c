/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koef_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:57:02 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/10 19:39:01 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_abs(int *i)
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
			ret[i][j] = -100;
			j++;
		}
		j = 0;
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
			if (tw - w > th - h && th - h < 0)
				s->kmap[th][tw] = th - h;
			else if (tw - w < 0)
				s->kmap[th][tw] = tw - w;
			check_abs(&s->kmap[th][tw]);
			tw++;
		}
		tw = 0;
		th++;
	}
}

void	koef_map(t_flr *s, int a)
{
	int	i;
	int	j;

	int fd = open("test_out", O_RDWR);
	i = 0;
	j = 0;
	s->kmap = alloc(s->m_h, s->m_w);
	while (i < s->m_h)
	{
		while (j < s->m_w)
		{
//				dprintf(fd, "%c\n", s->e_char);
			if (s->map[i][j] == s->e_char - a && s->kmap[i][j] != 0)
			{
				s->kmap[i][j] = 0;
				koef_count(s, i, j);
				koef_count(s, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}





	i = 0;
	j = 0;
	while (i < s->m_h)
	{
		while (j < s->m_w)
		{
			dprintf(fd, "%d\t", s->kmap[i][j]);
			j++;
		}
		dprintf(fd, "\n");
		j = 0;
		i++;
	}

}
