/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:22:00 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/03 18:34:47 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	pf(t_flr *s)
{
	int i;
	
	i = 0;
	while (i < s->p_h)
		ft_strdel(&s->piece[i++]);
	free(s->piece);
}

void	game(t_flr *s)
{
	t_crd	r;
	
	koef_map(s);
	read_piece(s);
	r = place_piece(s);
	if (r.h >= 0 && r.w >= 0)
	{
		ft_putnbr(r.h);
		ft_putchar(' ');
		ft_putnbr(r.w);
		ft_putchar('\n');
		s->last_sum = -1;
		s->last_h = -1;
		s->last_w = -1;
	}
	else
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
	}
	pf(s);
}
