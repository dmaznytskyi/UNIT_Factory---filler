/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:08:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/02 21:34:58 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_init(t_flr *s)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	get_next_line(0, &line);
	tmp = ft_strsplit(line, ' ');
	ft_strdel(&line);
	s->m_h = ft_atoi(tmp[1]);
	ft_strdel(&tmp[1]);
	s->m_w = ft_atoi(tmp[2]);
	ft_strdel(&tmp[2]);
	ft_strdel(&tmp[0]);
	free(tmp);
	if (!s->map)
		s->map = (char**)malloc(sizeof(char*) * (s->m_h + 1));
	s->map[s->m_h] = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < s->m_h)
	{
		get_next_line(0, &line);
		s->map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
}
