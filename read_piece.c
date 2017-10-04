/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:37:55 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/04 15:23:58 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(t_flr *s)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	get_next_line(0, &line);
	tmp = ft_strsplit(line, ' ');
	ft_strdel(&line);
	s->p_h = ft_atoi(tmp[1]);
	ft_strdel(&tmp[1]);
	s->p_w = ft_atoi(tmp[2]);
	ft_strdel(&tmp[2]);
	ft_strdel(&tmp[0]);
	free(tmp);
	s->piece = (char**)malloc(sizeof(char*) * (s->p_h + 1));
	s->piece[s->p_h] = 0;
	while (i < s->p_h)
	{
		fgnl(&line, 1);
		s->piece[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
}
