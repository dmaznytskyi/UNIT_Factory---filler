/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:08:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/04 15:00:43 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	read_map(t_flr *s)
{
	int		i;
	char	*line;
	int		test;

	i = 0;
	test = get_next_line(0, &line);
	ft_strdel(&line);
    if (test == 0)
        return (test);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < s->m_h)
	{
		fgnl(&line, 0);
		ft_strcpy(s->map[i], line + 4);
		ft_strdel(&line);
		i++;
	}
    return (test);
}
