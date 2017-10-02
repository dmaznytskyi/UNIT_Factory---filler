/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:45:49 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/02 19:38:14 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
#include <stdio.h>////////////////////////
#include <fcntl.h>////////////////////////

typedef struct	s_flr
{
	int		p_num;		//player num
	char	p_char;		//player char
	char	e_char;		//enemy char
	int		m_h;		//map height
	int		m_w;		//map width
	char	**map;		//map
	int		i_h;		//initial height coord
	int		i_w;		//initial width coord
	int		p_h;		//piece height
	int		p_w;		//piece width
	char	**piece;	//piece
	int		**kmap;		//map of koeff's
	int		last_h;		//last successfuly placed piece on h
	int		last_w;		//last successfuly placed piece on w
	int		last_sum;	//last koef_sum of piece
}				t_flr;

typedef struct	s_crd
{
	int	h;
	int	w;
}				t_crd;

void			init_struct(t_flr *s);

int				read_map(t_flr *s);
int				read_init(t_flr *s);
void			game(t_flr *s);
void			read_piece(t_flr *s);
t_crd			place_piece(t_flr *s);
void			koef_map(t_flr *s);
int				check_abs(int i);
int				ret_diff(int a, int b);
int				sum_koef_cnt(t_flr *s, int w, int h);
int				place_well(t_flr *s, int w, int h);

#endif
