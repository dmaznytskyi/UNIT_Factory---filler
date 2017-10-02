/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koef_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:57:02 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/02 20:16:46 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	nuluator(int ***s, int h, int w)
{
	int i;
	int j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			*s[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	alloc(int ***s, int h, int w)
{
	int	**ret;
	int i;
	int j;

	if (*s)
		nuluator(s, h, w);
	else
	{
		ret = (int**)malloc(sizeof(int*) * h);
		i = 0;
		while (i < h)
		{
			j = 0;
			ret[i] = (int*)malloc(sizeof(int) * w);
			while (j < w)
			{
				ret[i][j] = 0;
				j++;
			}
			i++;
		}
		*s = ret;
	}
}
	
int		ret_diff(int a, int b)
{
	int	c;

	c = a - b;
	if (c < 0)
		c *= -1;
	return (c);
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
			if (ret_diff(th, h) >= ret_diff(tw, w))
				s->kmap[h][w] = ret_diff(th, h);
			else
				s->kmap[h][w] = ret_diff(tw, w);
			tw++;
		}
		tw = 0;
		th++;
	}
}

void	koef_map(t_flr *s)
{
	int fd = open("test_out", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	int	i;
	int	j;

	i = 0;
	j = 0;
	alloc(&s->kmap, s->m_h, s->m_w);
	while (i < s->m_h)
	{
		while (j < s->m_w)
		{
			if (s->map[i][j] == '.')
				koef_count(s, i, j);
			else if (s->map[i][j] == s->e_char)
				s->kmap[i][j] = -42;
			else if (s->map[i][j] == s->e_char - 32)
				s->kmap[i][j] = -1;
			else
				s->kmap[i][j] = 4242;
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
