/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:45:34 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/06 15:45:07 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		p_num;
	int		fd;
	char	**tmp;
	t_flr	s;
   
	fd = open("test_out", O_RDWR);
	i = 0;
	p_num = 0;
	line = (char*)malloc(sizeof(char) * 1024);
	i = get_next_line(0, &line);
	dprintf(fd, "%s\n", line);
	if (ft_strchr(line, '1'))
		p_num = 1;
	if (ft_strchr(line, '2'))
		p_num = 2;
	i = get_next_line(0, &line);
	dprintf(fd, "%s\n", line);
	tmp = ft_strsplit(line, ' ');
	s.m_h = ft_atoi(tmp[1]);
	s.m_w = ft_atoi(tmp[2]);
	dprintf(fd, "%d %d\n", s.m_h, s.m_w);
	while (1)
	{
		i = get_next_line(0, &line);
		dprintf(fd, "%s\n", line);
		printf("\e[1m%d\t%d\e[32;0m\n", p_num, 0);
	}
	return (0);
}
