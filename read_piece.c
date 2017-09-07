/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:37:55 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/07 17:56:45 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(t_flr *s)
{
	int		i;
	char	*line;

	i = 0;
	line = (char*)malloc(sizeof(char) * (s->p_w + 1));
	s->piece = (char**)malloc(sizeof(char*) * (s->p_h + 1));
	s->piece[s->p_h] = 0;
	while (i < s->p_h)
	{
		get_next_line(0, &line);
		s->piece[i] = ft_strdup(line);
		i++;
	}
	free(line);
}
