/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:22:00 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/02 20:16:37 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
}
