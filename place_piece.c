/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:36:26 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/10 16:33:37 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_crd		place_piece(t_flr *s)
{
	t_crd	r;
	t_crd	r0;
	int		i;
	int		j;
	int		i0;
	int		j0;

	i = 0;
	j = 0;
	i0 = 0;
	while (i0 < s->p_h && i0 > 0)
	{
		s->p_char == 'o' ? (j0 = 0) : (j0 = s->p_w);
		while (j0 < s->p_w && j0 > 0)
		{
			if (s->piece[i0][j0] == '*')
			{
				r0.x = i0;
				r0.y = j0;
			}
			s->p_char == 'o' ? j0++ : j0--;
		}
		i0++;
	}
	while (i < s->m_h)
	{
		while (j < s->m_w)
		{
			j++;
		}
		i++;
		j = 0;
	}
	r.x = i;
	r.y = j;
	return (r);
}
