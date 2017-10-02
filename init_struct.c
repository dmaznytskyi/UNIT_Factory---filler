/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:28:30 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/02 21:35:36 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	initialize(t_flr *s)
{
	s->p_num = 0;
	s->p_char = 0;
	s->e_char = 0;
	s->m_h = 0;
	s->m_w = 0;
	s->map = 0;
	s->p_h = 0;
	s->p_w = 0;
	s->last_sum = -1;
	s->kmap = NULL;
}

static void	letter(t_flr *s, char *line)
{
	if (ft_strchr(line, '1'))
	{
		s->p_num = 1;
		s->p_char = 'o';
		s->e_char = 'x';
	}
	else if (ft_strchr(line, '2'))
	{
		s->p_num = 2;
		s->p_char = 'x';
		s->e_char = 'o';
	}
}

void		init_struct(t_flr *n)
{
	char	*line;
	int		h;
	int		w;

	h = 0;
	w = 0;
	initialize(n);
	get_next_line(0, &line);
	letter(n, line);
	ft_strdel(&line);
	read_init(n);
	game(n);
}
