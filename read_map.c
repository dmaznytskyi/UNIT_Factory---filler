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

int 	read_map(t_flr *s)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	int test = get_next_line(0, &line);
    if (test == 0)
        return (test);
	tmp = ft_strsplit(line, ' ');
	s->m_h = ft_atoi(tmp[1]);
	s->m_w = ft_atoi(tmp[2]);
	s->map = (char**)malloc(sizeof(char*) * (s->m_h + 1));
	s->map[s->m_h] = 0;
	test = get_next_line(0, &line);
	while (i < s->m_h)
	{
		test = get_next_line(0, &line);
		tmp = ft_strsplit(line, ' ');
		s->map[i] = ft_strdup(tmp[1]);
		i++;
	}
    return (test);
}
