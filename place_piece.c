/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:36:26 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/01 16:47:32 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			place_well(t_flr *s, int w, int h)
{
	int	l_w;
	int	l_h;
	int	one_touch;

	l_h = 0;
	one_touch = 0;
	while (l_h < s->p_h)
	{
		l_w = 0;
		while (l_w < s->p_w)
		{
			if (s->piece[l_h][l_w] == '*' &&
					(s->map[h + l_h][w + l_w] != s->e_char ||
					s->map[h + l_h][w + l_w] != s->e_char - 32) &&
					(s->map[h + l_h][w + l_w] == s->p_char - 32 ||
					s->map[h + l_h][w + l_w] == s->p_char) && !one_touch)
			{
				one_touch = 1;
				l_w++;
			}
			else if (s->piece[l_h][l_w] == '.' || (s->piece[l_h][l_w] == '*'
						&& s->map[h + l_h][w + l_w] == '.'))
				l_w++;
			else
				return (0);
		}
		l_h++;
	}
	return (one_touch);
}

int			sum_koef_cnt(t_flr *s, int w, int h)
{
	int th;
	int tw;
	int	res;

	th = 0;
	tw = 0;
	res = 0;
	koef_map(s, 32);
	while (th < s->p_h)
	{
		while (tw < s->p_w)
		{
			res += s->kmap[h + th][w + tw];
			tw++;
		}
		tw = 0;
		th++;
	}
	return (res);
}

t_crd		place_piece(t_flr *s)
{
	t_crd	ret;
	int		th;
	int		tw;
	int		tsum;

	th = 0;
	tw = 0;
	while (th < s->m_h - s->p_h)
	{
		while (tw < s->m_w - s->p_w)
		{
			if (place_well(s, tw, th))
			{
				tsum = sum_koef_cnt(s, tw, th);
//				printf("tsum %d\n", tsum);
//				printf("%d %d\n", th, tw);
				if (tsum < s->last_sum || s->last_sum == 0)
				{
					s->last_h = th;
					s->last_w = tw;
					s->last_sum = tsum;
				}
			}
			tw++;
		}
		tw = 0;
		th++;
	}
	ret.h = s->last_h;
	ret.w = s->last_w;
	return (ret);
}
