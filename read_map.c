/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:08:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/06 19:40:55 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_flr *s)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	line = (char*)malloc(sizeof(char) * 1024);
	s->map = (char**)malloc(sizeof(char*) * (s->m_h + 5));
	s->map[s->m_h] = 0;
	get_next_line(0, &line);
	while (!ft_strchr(line, 'P') || s->map[i] != 0)
	{
		get_next_line(0, &line);
		tmp = ft_strsplit(line, ' ');
		s->map[i] = ft_strdup(tmp[1]);
		i++;
	//	despit(tmp);
	}
}
