/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:08:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/12 19:52:06 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_flr *s)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	s->map = (char**)malloc(sizeof(char*) * (s->m_h + 1));
	s->map[s->m_h] = 0;
	get_next_line(0, &line);
	while (i < s->m_h)
	{
		get_next_line(0, &line);
		tmp = ft_strsplit(line, ' ');
		s->map[i] = ft_strdup(tmp[1]);
		i++;
	}
	get_next_line(0, &line);
	tmp = ft_strsplit(line, ' ');
	s->p_h = ft_atoi(tmp[1]);
	s->p_w = ft_atoi(tmp[2]);
	ft_strdel(&line);
}
