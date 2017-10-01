/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:08:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/01 19:06:50 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_flr *s)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	get_next_line(3, &line);
	tmp = ft_strsplit(line, ' ');
	s->m_h = ft_atoi(tmp[1]);
	s->m_w = ft_atoi(tmp[2]);
	s->map = (char**)malloc(sizeof(char*) * (s->m_h + 1));
	s->map[s->m_h] = 0;
	get_next_line(3, &line);
	while (i < s->m_h)
	{
		get_next_line(3, &line);
		tmp = ft_strsplit(line, ' ');
		s->map[i] = ft_strdup(tmp[1]);
		i++;
	}
}
