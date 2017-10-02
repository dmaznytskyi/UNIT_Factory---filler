/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:28:30 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/02 13:08:26 by dmaznyts         ###   ########.fr       */
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
	s->i_h = 0;
	s->i_w = 0;
	s->p_h = 0;
	s->p_w = 0;
	s->last_sum = 0;
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
/*
static void find_pos(t_flr *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s->m_h)
	{
		while (j < s->m_w)
		{
			if (s->map[i][j] == s->p_char + 32)
			{
				s->i_h = i;
				s->i_w = j;
			}
			j++;
		}
		i++;
	}
}
*/
/*
static void	print_info(t_flr *s)
{
	int		fd;

	fd = open("test_out", O_RDWR);
	dprintf(fd, "player	- %d\n", s->p_num);
	dprintf(fd, "p_char	- %c\n", s->p_char);
	dprintf(fd, "e_char	- %c\n", s->e_char);
	dprintf(fd, "map	- h-%d w-%d\n", s->m_h, s->m_w);
	dprintf(fd, "piece	- h-%d w-%d\n", s->p_h, s->p_w);
}
*/
void		init_struct(t_flr *n)
{
//	char	**tmp;
	char	*line;
	int		h;
	int		w;

	h = 0;
	w = 0;
	initialize(n);
	get_next_line(0, &line);
//	printf("line1 readed\n");
	letter(n, line);
//	get_next_line(0, &line);
//	tmp = ft_strsplit(line, ' ');
//	n->m_h = ft_atoi(tmp[1]);
//	n->m_w = ft_atoi(tmp[2]);
//	get_next_line(0, &line);
//	read_map(n);
//	find_pos(n);
//	print_info(n);
}
