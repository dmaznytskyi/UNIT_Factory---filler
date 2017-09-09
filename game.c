/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:22:00 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/09 18:06:08 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	game(t_flr *s)
{
	t_crd	r;

	while (1)
	{
		read_piece(s);
		r = place_piece(s);
		if (r.x > 0 && r.y > 0)
		{
			ft_putnbr(r.x);
			ft_putchar(' ');
			ft_putnbr(r.y);
			ft_putchar('\n');
		}
		else
		{
			ft_putnbr(-100);
			ft_putchar(' ');
			ft_putnbr(-100);
			ft_putchar('\n');
		}	
	}
}
